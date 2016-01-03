#include <stdio.h>
#include <math.h>

// PRIME TABLES: http://www.bigprimes.net/archive/prime/
// QUESTIONS: http://crypto.stackexchange.com/questions/5262/rsa-and-prime-difference

/*  Function to estimate the k-th prime number */
void compute_pk(long long k) {
    long long pk;
    double ln_k = log(k);
    double ln2_k = log(log(k));

    if(k >= 688383) {
        pk = (long long) round(k*(ln_k + ln2_k - 1 + (ln2_k - 2.0)/ln_k));
        printf("%lldth prime number: pk <= %lld\n", k, pk);
        return;
    }

    if(k >= 3) {
        pk = (long long) round(k*(ln_k + ln2_k - 1 + (ln2_k - 2.1)/ln_k));
        printf("%lldth prime number: pk >= %lld\n", k, pk);
        return;
    }
}

/*  Function to estimate the amount of primes less than x */
void primeCounting(long long x) {
    double pi_x;            /* Considering π(x) as the amount of primes */
    float ln_x = log(x);    /* Extra variable to avoid computing log(x) again */
    double growthRate;      /* Growth rate */
    double limit_pi;        /* Limit that establish the relation between π(x) and growth rate. */

    printf("For x = %lld:\n", x);

    if(x >= 2953652287) {
        pi_x = (x/ln_x)*(1.0 + 1.0/ln_x + 2.334/pow(ln_x, 2));
        printf("Amount: π(x) <= %lld\n", (long long) round(pi_x));
    } else if(x >= 88783) {
        pi_x = (x/ln_x)*(1.0 + 1.0/ln_x + 2.0/pow(ln_x, 2));
        printf("Amount: π(x) >= %lld\n", (long long) round(pi_x));
    } else if(x >= 60184) {
        pi_x = x/(ln_x - 1.1);
        printf("Amount: π(x) <= %lld\n", (long long) round(pi_x));
    } else if(x >= 5393) {
        pi_x = x/(ln_x - 1.0);
        printf("Amount: π(x) >= %lld\n", (long long) round(pi_x));
    }

    /*  Growth rate with approximated value. One way to compute it is using
        logarithmic integral of (1/ln(t))dt, with limits being [2, x].
    */
    growthRate = x/ln_x;

    /*  Limit will be used to prove that, as x tends to infinity,
        the relation of π(x) with growth rate tends to 1.0 */
    limit_pi = pi_x/growthRate;

    printf("Growth rate: %lf\n", growthRate);
    printf("Limit: %lf\n\n", limit_pi);
}

long long get_limit_pierre(long long x) {
    return (long long) round(x*(1.0 + 1.0/(25*pow(log(x), 2))));
}

long long get_limit_schoenfeld(long long x) {
    return (long long) round(x*(1.0 + 1.0/16597));
}

/*  Function to estimate the lowest interval containing at least a prime. */
void smallestInterval(long long x) {
    long long lowerBound;
    long long upperBound;

    /*  Limit proposed by Rosser and Schoenfeld:
        [x, x + x/16597], for x >= 2010759.9

        Limit proposed by  Pierre Dusart:
        [x, x + x/25(lnx)^2], for x >= 396738

        The Pierre limit has best results for x >= e^25.77
    */

    lowerBound = x;
    if(x >= exp(25.77))     upperBound = get_limit_pierre(x);
    else if(x >= 2010760)   upperBound = get_limit_schoenfeld(x);
    else if(x >= 396738)    upperBound = get_limit_pierre(x);

    /*  p+1 = next prime */
    printf("Lowest interval between p and p+1 = [%lld, %lld]\n",
    lowerBound, upperBound);
}

/*
    Function to estimate maximum gap between primes less than X.
    Theorem established by Kevin Ford, Ben Green, Sergei Konyagin,
    James Maynard e Terence Tao.
*/
void maxGap(long long x) {
    double gx;  /* Maximum gap */
    double fx;
    long long limit;

    fx = log(log(log(x)));
    gx = fabs((log(x)*log(log(x))*log(log(log(log(x)))))/pow(log(log(log(x))), 2));
    printf("Gap: %lf\n", gx);
}

int main() {
    compute_pk(688383);
    compute_pk(1399999901);
    compute_pk(20);
    printf("\n");

    primeCounting(88783);
    primeCounting(2953652287);
    printf("\n");

    smallestInterval(179424691);
    smallestInterval(32416187701);
    smallestInterval(32416188583);
    printf("\n");

    maxGap(32416190071);
    maxGap(179424755);
    maxGap(32416187747);
    maxGap(32416189859);
    return 0;
}
