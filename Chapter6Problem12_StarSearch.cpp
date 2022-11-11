//Sergio Lucio
//Beginning Programming
//Professor Goulden
//Star Search

#include<iostream>
#include<iomanip>
using namespace std;

bool isValid(double);
void getJudgeData(double&);
void calcScore(double, double, double, double, double);
double findHighest(double, double, double, double, double);
double findLowest(double, double, double, double, double);


int main()
{
	double score1, score2, score3, score4, score5;
	double highestScore;
	double lowestScore;

	cout << fixed << showpoint << setprecision(2);

	cout << "Wlecome to star search" << endl;
	cout << "I will ask you to input the auditioners 5 scores, drop the highest and lowest, ";
	cout << "and average the 3 remainding scores." << endl;

	getJudgeData(score1);
	getJudgeData(score2);
	getJudgeData(score3);
	getJudgeData(score4);
	getJudgeData(score5);

	calcScore(score1, score2, score3, score4, score5);

	highestScore = findHighest(score1, score2, score3, score4, score5);
	lowestScore = findLowest(score1, score2, score3, score4, score5);

	cout << "the highest score was " << highestScore << " and the lowest score was " << lowestScore << "." << endl;

	return 0;
}
bool isValid(double score)
{
	bool result;

	result = !(score < 0 || score > 10);
	return result;
}

void getJudgeData(double& score)
{
	static int loop = 1;
	cout << "Please enter judge score number " << loop << ": " << endl;
	cin >> score;

	if (!isValid(score)) {
		// re get the score
		cout << "re enter score greater than 0 and less or equal to 10" << endl;
		getJudgeData(score);
		// prevents the loop from being incremented
		return;
	}

	loop++;
}

void calcScore(double num1, double num2, double num3, double num4, double num5)
{
	double lowestGrade, highestGrade;
	double score;
	double average;

	lowestGrade = findLowest(num1, num2, num3, num4, num5);
	highestGrade = findHighest(num1, num2, num3, num4, num5);

	score = num1 + num2 + num3 + num4 + num5 - lowestGrade;
	average = (num1 + num2 + num3 + num4 + num5 - lowestGrade - highestGrade) / 3;
	cout << "Your average is: " << average << endl;


}

double findHighest(double num1, double num2, double num3, double num4, double num5) // find the highest integer
//
{
	double highest = num1;

	if (num2 >= highest)
		highest = num2;
	if (num3 >= highest)
		highest = num3;
	if (num4 >= highest)
		highest = num4;
	if (num5 >= highest)
		highest = num5;

	return highest;
}

double findLowest(double num1, double num2, double num3, double num4, double num5) // find the lowest number
{
	double lowest = num1;

	if (num1 <= num2)
		lowest = num1;
	else if (num1 > num2)
		lowest = num2;

	if (lowest <= num3)
		lowest = lowest;
	else if (lowest > num3)
		lowest = num3;

	if (lowest <= num4)
		lowest = lowest;
	else if (lowest > num4)
		lowest = num4;

	if (lowest <= num5)
		lowest = lowest;
	else if (lowest > num5)
		lowest = num5;

	return lowest;
}