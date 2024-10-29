::/*#! 2> /dev/null                                   #
@ 2>/dev/null # 2>nul & echo off & goto BOF           #
if [ -z "${SIREUM_HOME}" ]; then                      #
  echo "Please set SIREUM_HOME env var"               #
  exit -1                                             #
fi                                                    #
exec "${SIREUM_HOME}/bin/sireum" slang run "$0" "$@"    #
:BOF
setlocal
if not defined SIREUM_HOME (
  echo Please set SIREUM_HOME env var
  exit /B -1
)
"%SIREUM_HOME%\bin\sireum.bat" slang run %0 %*
exit /B %errorlevel%
::!#*/
// #Sireum

import org.sireum.String.escape
import org.sireum._

val home = Os.slashDir.up

val sireum = Os.path(Os.env("SIREUM_HOME").get) / "bin" / (if (Os.isWin) "sireum.bat" else "sireum")

var platform: String = "JVM"
val expectedPlatforms: Set[String] = Set(ISZ("JVM", "Linux", "seL4"))
var sysml_aadl_libraries: ISZ[Os.Path] = ISZ()

def exit(msg: String): Unit = {
  cprintln(T, msg)
  Os.exit(-1)
  halt("")
}

def set(a: String): Unit = {
  if (expectedPlatforms.contains(a)) {
    platform = a
  } else {
    val cand = Os.path(a)
    if (cand.exists && cand.isDir) {
      sysml_aadl_libraries = sysml_aadl_libraries :+ cand
    } else {
      exit(s"Expecting either the platform or the location of the sysml-aadl-libraries but can't resolve '$a'")
    }
  }
}

for (arg <- Os.cliArgs) {
  set(arg)
}

if (sysml_aadl_libraries.isEmpty) {
  if ((home.up.up.up / "sysmlv2-models").exists) {
    sysml_aadl_libraries = ISZ(home.up.up.up / "sysmlv2-models" / "sysml-aadl-libraries")
  } else {
    exit("Please specify the location of the directory that contains aadl.library and aadl.propertysets")
  }
}

var codegeArgs: ISZ[String] = ISZ(
    sireum.value, "hamr", "sysml", "codegen",
    "--platform", platform,
    "--sourcepath", st"${(sysml_aadl_libraries, s"${Os.pathSepChar}")}${Os.pathSepChar}${home.value}".render,
    (home / "RTS.sysml").value)

val results = Os.proc(codegeArgs).at(home.up.up).console.run()

Os.exit(results.exitCode)