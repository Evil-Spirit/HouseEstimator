copy "C:\SASHA\Config_new\Source\Bind\z_VCL.pkg" "C:\SASHA\TOLUA\tolua++-1.0.3\src\bin\z_VCL.pkg"

cd C:\SASHA\TOLUA\tolua++-1.0.3\src\bin
tolua_103_app.exe -o z_VCL.cpp z_VCL.pkg

copy "C:\SASHA\TOLUA\tolua++-1.0.3\src\bin\z_VCL.cpp" "C:\SASHA\Config_new\Source\Bind\z_VCL.cpp"
del z_VCL.pkg
del z_VCL.cpp
