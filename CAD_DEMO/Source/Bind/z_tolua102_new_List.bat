copy "C:\SASHA\Config_new\Source\Bind\z_List.pkg" "C:\SASHA\TOLUA\tolua++-1.0.3\src\bin\z_List.pkg"

cd C:\SASHA\TOLUA\tolua++-1.0.3\src\bin
tolua_103_app.exe -o z_List.cpp z_List.pkg

copy "C:\SASHA\TOLUA\tolua++-1.0.3\src\bin\z_List.cpp" "C:\SASHA\Config_new\Source\Bind\z_List.cpp"
del z_List.pkg
del z_List.cpp
