g++ main.cpp -o problem1.exe

FOR /L %%A IN (1,1,10) DO (
  echo test %%A
  type data\%%A.in
  Problem1 <data\%%A.in > data\%%A.out.jason
  fc data\%%A.out data\%%A.out.jason

)
