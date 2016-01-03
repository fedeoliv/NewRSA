% getMaxGap: Function to compute the maximum gap between consecutive primes less than X.
%			 It can be used to optimize RSA cryptography, when we need to recalculate the value of d.
%			 When we need to generate other value to d (private key exponent), this function can optimize
%			 the search for a new prime, getting the previous prime.

function gap = getMaxGap(x)
	% Function f(x) that will replace the constant c that was used in previous formulas.
	% f(x) is a result shown by James Maynard and his team of mathematicians.
	
	fx = log(log(log(x)));
	gx = fx*(log(x)*log(log(x))*log(log(log(log(x)))))/(log(log(log(x))));
	gap = x - abs(round(gx));
