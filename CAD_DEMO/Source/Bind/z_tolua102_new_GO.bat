copy "C:\SASHA\Config_new\Source\Bind\z_GO.pkg" "C:\SASHA\TOLUA\tolua++-1.0.3\src\bin\z_GO.pkg"

cd C:\SASHA\TOLUA\tolua++-1.0.3\src\bin
tolua_103_app.exe -o z_GO.cpp z_GO.pkg

copy "C:\SASHA\TOLUA\tolua++-1.0.3\src\bin\z_GO.cpp" "C:\SASHA\Config_new\Source\Bind\z_GO.cpp"
del z_GO.pkg
del z_GO.cpp
