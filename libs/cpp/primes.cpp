/*
 * Written by Theodosis "ted" Sourgkounis.
 * inspired by Dionysis "dionyziz" Zindros.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
using namespace std;

int *primes;


int main(){
    
    long N;
    cin >> N;
    struct timeval t1, t2, lapsed;
    struct timezone tzp;

    gettimeofday(&t1, &tzp);
    
    primes = (int*) malloc( sizeof( int ) * 1000000 );
    
    primes[ 0 ] = 2;
    primes[ 1 ] = 3;
    primes[ 2 ] = 5;
    primes[ 3 ] = 7;
    primes[ 4 ] = 11;
    primes[ 5 ] = 13;

    int count = 6;
    long last = 13;
    
    int estimate = floor( N * log( N ) + N * log( log( N ) ) );
    for( int i = 17; count <= N; i += 2 ){
        bool isprime = true;
        for( int j = 0; j < count; ++j ){
            if( primes[ j ] * primes[ j ] > i ){
                break;
            }
            if( i % primes[ j ] == 0 ){
                isprime = false;
                break;
            }
        }
        if( isprime ){
            if( i * i < estimate ){
                primes[ count ] = i;
            }
            last = i;
            ++count;
        }
    }
    
    gettimeofday(&t2, &tzp);
    if( t1.tv_usec > t2.tv_usec ){
        t2.tv_usec += 1000000;
        t2.tv_sec--;
    }
    lapsed.tv_usec = t2.tv_usec - t1.tv_usec;
    lapsed.tv_sec = (int) ( t2.tv_sec - t1.tv_sec );
    printf("Time elapsed: %d.%06dsec\n", (int)lapsed.tv_sec, (int)lapsed.tv_usec);  
    cout << last << endl;
    return 0;
}
