copy "C:\SASHA\Config_new\Source\Bind\z_All.pkg" "C:\SASHA\TOLUA\tolua++-1.0.3\src\bin\z_All.pkg"

cd C:\SASHA\TOLUA\tolua++-1.0.3\src\bin
tolua_103_app.exe -o z_All.cpp z_All.pkg

copy "C:\SASHA\TOLUA\tolua++-1.0.3\src\bin\z_All.cpp" "C:\SASHA\Config_new\Source\Bind\z_All.cpp"
del z_All.pkg
del z_All.cpp
