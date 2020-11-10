#include <iostream>
#include<cmath>
#include<vector>
#include <iomanip>
#include <random>
double Function(const double& x, const double& y)
{
	return cos(x)* cos(y)* exp(y / 2);
	//return exp(-pow(x, 2))* exp(-pow(y, 2)) / (1 + pow(x, 2) + pow(y, 2));
}
void sort(std::vector < std::pair<std::pair<double, double>, double>> & xrom)
{
	std::pair<std::pair<double, double>, double> asa;
	for (int j = 0; j < 4; j++)         // сортируем в порядке возрастания
	{
		for (int p = (4 - 1); p >= (j + 1); p--)
		{
			if (xrom[p].second < xrom[p - 1].second)
			{
				asa = xrom[p];
				xrom[p] = xrom[p - 1];
				xrom[p - 1] = asa;
			}
		}
	}
}
int main()
{
	double mean = 0;
	double Max_value = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> scope(-2, 2);
	std::uniform_real_distribution<double> p_(0, 1);
	double probability = 0.4;
	std::vector < std::pair<std::pair<double, double>, double>> vec(4);
	for (size_t j = 0; j < 4; j++)
	{
		vec[j].first.first = scope(gen);
		vec[j].first.second = scope(gen);
		vec[j].second = Function(vec[j].first.first, vec[j].first.second); //находим значение функции
		mean = mean + vec[j].second;

	}
	std::cout << "N: 0" << std::endl;
	for (size_t j = 0; j < 4; j++)
	{
		std::cout << "x: " << vec[j].first.first << "\t y: " << vec[j].first.second << "\t fit: " << vec[j].second << std::endl;
	}
	sort(vec);
	Max_value = vec[3].second;
	std::cout << " Average: " << mean / 4 << " Max: " << vec[3].second << std::endl;
	for (size_t i = 1; i <= 10; i++)
	{
		mean = 0;
		for (auto j = 0; j < 4; j++)   //мутация
		{
			auto p = p_(gen);
			if (p < probability)
			{
				vec[j].first.first = vec[j].first.first + p / 2;
				vec[j].first.second = vec[j].first.second + p / 2;
				vec[j].second = Function(vec[j].first.first, vec[j].first.second);
			}
		}
		sort(vec);
		vec[0].first.first = vec[3].first.first;
		vec[3].first.first = vec[1].first.first;
		vec[1].first.first = vec[2].first.first;
		vec[2].first.first = vec[0].first.first;


		vec[0].first.second = vec[2].first.second;
		vec[2].first.second = vec[1].first.second;
		vec[1].first.second = vec[3].first.second;
		for (size_t j = 0; j < 4; j++)
		{
			vec[j].second = Function(vec[j].first.first, vec[j].first.second); //находим значение функции
			mean = mean + vec[j].second;

		}
		std::cout << "N: " << i << std::endl;
		for (size_t j = 0; j < 4; j++)
		{
			std::cout << "x: " << vec[j].first.first << "\t y: " << vec[j].first.second << "\t fit: " << vec[j].second << std::endl;
		}
		sort(vec);
		Max_value = vec[3].second;
		mean = mean / 4;
		std::cout << " Average: " << mean << " Max: " << vec[3].second << std::endl;



	}





}