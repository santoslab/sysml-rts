::#! 2> /dev/null                                   #
@ 2>/dev/null # 2>nul & echo off & goto BOF         #
if [ -z ${SIREUM_HOME} ]; then                      #
  echo "Please set SIREUM_HOME env var"             #
  exit -1                                           #
fi                                                  #
exec ${SIREUM_HOME}/bin/sireum slang run "$0" "$@"  #
:BOF
setlocal
if not defined SIREUM_HOME (
  echo Please set SIREUM_HOME env var
  exit /B -1
)
%SIREUM_HOME%\\bin\\sireum.bat slang run "%0" %*
exit /B %errorlevel%
::!#
// #Sireum

import org.sireum._

val root: Os.Path = Os.slashDir.up
val hamrDir: Os.Path = root / "hamr"
val cDir = hamrDir / "c"
val camkesDir = hamrDir / "camkes"
val slangDir = hamrDir / "slang"
val slangRMDir = hamrDir / "slang-rm"

val toKeep = ops.ISZOps(ISZ(
  (root / "bin"),
  (camkesDir / "kernel" / "domain_schedule.c"),
  (camkesDir/ "settings.cmake"),
  (slangDir / "bin" / "transpile-sel4-cust.cmd"),

  (cDir / "ext-c"),
  (slangDir / ".idea"),
  (slangDir / "src" / "main" / "component"),
  (slangDir / "src" / "test" / "bridge"),
  (slangDir / "src" / "test" / "system"),
  (slangDir / ".idea"),
  (slangRMDir / "src" / "main" / "component"),
  (slangRMDir / "src" / "test" / "bridge"),
  (slangRMDir / "src" / "test" / "system")
))


def rec(p: Os.Path, onlyDelAutoGen: B): Unit = {
  if(p.isFile) {
    if ((!toKeep.contains(p) && !onlyDelAutoGen) || ops.StringOps(p.read).contains("Do not edit")) {
      p.remove()
      println(s"Removed file: $p")
    }
  } else {
    for (pp <- p.list) {
      rec(pp, toKeep.contains(p) || onlyDelAutoGen)
    }
    if (p.list.isEmpty) {
      p.removeAll()
      println(s"Removed empty directory: $p")
    }
  }
}
rec(hamrDir, F)
