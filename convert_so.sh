#.so文件的目的是给其他独立程序提供接口，所以最好不要在里面写main函数，这样容易造成重复
clang -c -fPIC test.c -o test.o
clang -shared -o libtest.so test.o