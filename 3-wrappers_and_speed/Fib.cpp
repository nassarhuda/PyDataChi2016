// timing functions from // http://stackoverflow.com/questions/17432502/how-can-i-measure-cpu-time-and-wall-clock-time-on-both-linux-windows
// main function modified by Huda

#include<iostream>
using namespace std;

//  Windows
#ifdef _WIN32
#include <Windows.h>
double get_wall_time(){
    LARGE_INTEGER time,freq;
    if (!QueryPerformanceFrequency(&freq)){
        //  Handle error
        return 0;
    }
    if (!QueryPerformanceCounter(&time)){
        //  Handle error
        return 0;
    }
    return (double)time.QuadPart / freq.QuadPart;
}
double get_cpu_time(){
    FILETIME a,b,c,d;
    if (GetProcessTimes(GetCurrentProcess(),&a,&b,&c,&d) != 0){
        //  Returns total user time.
        //  Can be tweaked to include kernel times as well.
        return
            (double)(d.dwLowDateTime |
            ((unsigned long long)d.dwHighDateTime << 32)) * 0.0000001;
    }else{
        //  Handle error
        return 0;
    }
}
//  Posix/Linux
#else
#include <time.h>
#include <sys/time.h>
double get_wall_time(){
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        //  Handle error
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
double get_cpu_time(){
    return (double)clock() / CLOCKS_PER_SEC;
}
#endif

// iterative version
int Fibonacci(int n)
{
	int x = 0;
	int y = 1;
	int t;
	for(int i=1; i<n; ++i)
	{
	    t = x;
	    x = y;
	    y = t+y;
	}
	return y;
}


int main(int argc, char* argv[])
{		


	
	int a;
	if ( argc > 1 ) {
    a = atoi( argv[1] );
    }
    
    int f;
    double t0 = get_wall_time();
    for (int i = 0; i<10;++i)
    f = Fibonacci(a);
    double t1 = get_wall_time() - t0;
	cout << "From iterative function:" << f << endl;
	cout << "Elapsed " << t1 << " seconds. " << endl;
	cout << endl;
	return 0;
}