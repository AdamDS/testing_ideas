/* Bayes_slot.cpp - ADS 5*15*14
 Play two slot machines and determine which has
 the better payout probability. Bayesian inference
 probabilities output after each pull. Using a 
 Recursive Bayesian Filter, a running probability
 for which slot has the better odds is printed.
*/
#include <iostream>
#include <cstdlib> //rand, srand
#include <ctime>
using namespace std;

int main() {
	double P_R;	//probability red
	double r;	//random number
	char color;
	bool game_over = false;
	double winprobR, winprobB;
	int plays, hitR, hitB, playR, playB;
	double temp;
	//initial values
	plays = 0;
	hitR = 0;
	hitB = 0;
	playR = 0;
	playB = 0;
	
	P_R = 0.5;	//equal choice red
		
	srand(time(NULL));
	r = (double)rand()/(double)RAND_MAX;
	double high_prob = 0.2;
	double low_prob = 0.1;
	if (r>0.5) {
		winprobR = low_prob;	
		winprobB = high_prob;
	} else {
		winprobR = high_prob;	
		winprobB = low_prob;
	}
	const double P_J_R = winprobR;	//probability jackpot given red
	const double P_J_B = winprobB;	//probability jackpot given blue
	cout << "P(J|R) = " << P_J_R << endl;
	cout << "P(NJ|R) = " << (1 -P_J_R) << endl;
	cout << "P(J|B) = " << P_J_B << endl;
	cout << "P(NJ|B) = " << (1 -P_J_B) << endl;
	//what is the probability that the red slot machine 
	//is the one more likely to payout (10% v 20%) given 
	//playing the red machine and getting a jackpot?
	//P(J|R) = P(R|J)*P(J)/P(R)
	//play red and get not jackpot
	//P(NJ|R) = P(R|NJ)*P(NJ)/P(R)
	//P(R) = 1-P(B)
	//P(J) = 0.1 or 0.2, P(J|a) = 0.1 & P(J|a') = 0.2
	//P(NJ) = 0.9 or 0.8, P(NJ|a) = 0.9 & P(NJ|a') = 0.8
	while (!game_over) {
		cout << "\tP(R) = " << P_R << "\t\t" << (1 -P_R) << " = P(B)\n";
		//r = (double)rand()/(double)RAND_MAX;
		r = (double)(rand() % 1000)/(double)1000;
		//cout << r << endl;
		cout << "Play red or blue or guess or exit (r/b/g/other): ";
		cin >> color;
		
		if (color=='r') {	//play red
			plays++;
			playR++;
			if (r<=winprobR) {
				P_R = high_prob*P_R/((high_prob*P_R) +(low_prob*(1 -P_R)));
				hitR++;
				cout << "Jackpot";
			} else {
				P_R = (1 -high_prob)*P_R/(((1 -high_prob)*P_R) +((1 -low_prob)*(1 -P_R)));
				cout << "Not a jackpot";
			}
			
		} else if (color=='b') {	//play blue
			plays++;
			playB++;
			if (r<=winprobB) {
				P_R = 1 -(high_prob*(1 -P_R)/((low_prob*P_R) +(high_prob*(1 -P_R))));
				hitB++;
				cout << "Jackpot";
			} else {
				P_R = 1 -((1 -high_prob)*(1 -P_R)/(((1 -low_prob)*P_R) +((1 -high_prob)*(1 -P_R))));
				cout << "Not a jackpot";
			}
			
		} else if (color=='g') {	//guess
			cout << "What slot has the better payout? ";
			cin >> color;
			if ((color=='r' && winprobR>winprobB) || (color=='b' && winprobB>winprobR))
				cout << "\n\t\tCorrect! You win!\n";
			else
				cout << "\n\t\tNope! You lose!\n";
			game_over = true;
		} else {	//not r or b entered
			game_over = true;
		} //if color
		
		if (game_over) {
			cout << endl << "You played red " << playR << " times out of " << plays;
			cout << " with " << hitR << " red jackpots" << endl;
			cout << "You played blue " << playB << " times out of " << plays;
			cout << " with " << hitB << " blue jackpots" << endl;
			cout << "Bayes thinks the better slot is ";
			cout << ((P_R > (1 -P_R)) ? "red\n" : "blue\n");
			cout << "The better slot was " << ((winprobR > winprobB) ? "red\n" : "blue\n");
			cout << "\nPlay again (y/n)? ";
			cin >> color;
			if (color=='y') {
				game_over = false;
				P_R = 0.5;
				plays = 0;
				hitR = 0;
				hitB = 0;
				playR = 0;
				playB = 0;
				cout << endl << endl;
			}
		}
		
	} //while !game_over

	return 0;
}
