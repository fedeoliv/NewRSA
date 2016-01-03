% generatePrime: Given a prime X, returns the previous prime.

function prime = generatePrime(x)
	prime = 1;
	i = gap = getMaxGap(x);

	while(i > 0)
		if(isPrime(i))
			prime = i;
			break;
		end
		i--;
	end

	originalInterval = x - prime;
	maxInterval = gap - prime;

	printf('\Interval <= %d\n', gap);
	printf('Prime number found: %d\n', prime);
	printf('\nOriginal interval:\n');
	printf("%d - %d = %d\n", x, prime, originalInterval);
	printf('\nMaximum interval:\n');
	printf("%d - %d = %d\n", gap, prime, maxInterval);
	printf("Intervals reduction: %d%% (%d intervals)\n", 100 - ((gap - prime)*100)/(x - prime), originalInterval - maxInterval);
