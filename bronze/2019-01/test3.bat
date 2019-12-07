g++ problem%1.cpp -o problem%1.exe
set data=data%1

FOR /L %%A IN (1,1,3) DO (
  echo test %%A
  type %data%\%%A.in
  Problem%1 <%data%\%%A.in > %data%\%%A.out.jason
  fc %data%\%%A.out %data%\%%A.out.jason

)
