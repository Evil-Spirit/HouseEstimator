copy "C:\SASHA\Config_new\Source\Bind\z_VisIt.pkg" "C:\SASHA\TOLUA\tolua++-1.0.3\src\bin\z_VisIt.pkg"

cd C:\SASHA\TOLUA\tolua++-1.0.3\src\bin
tolua_103_app.exe -o z_VisIt.cpp z_VisIt.pkg

copy "C:\SASHA\TOLUA\tolua++-1.0.3\src\bin\z_VisIt.cpp" "C:\SASHA\Config_new\Source\Bind\z_VisIt.cpp"
del z_VisIt.pkg
del z_VisIt.cpp
