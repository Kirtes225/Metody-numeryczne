#pragma once

class Punkt {
public:
	double x;
	double y;

	Punkt() {
		x = 0.;
		y = 0.;
	}
};

double* Lagrange(Punkt* punkt, int wezly) //Wspó³czynniki b z wielomianu postaci Newtona
{
	double* b = new double[wezly];

	for (int i = 0; i < wezly; i++) {
		b[i] = 0.;
	}

	double d = 1.;

	for (int k = 0; k < wezly; k++)
	{
		for (int i = 0; i <= k; i++)
		{
			d = 1.;
			for (int j = 0; j <= k; j++)
			{
				if (j != i)
					d *= (punkt[i].x - punkt[j].x);
			}
			b[k] += (punkt[i].y / d);
		}
	}

	return b;
}

double wartosc(Punkt* punkt, int wezly, double podanyPkt) //Wartoœæ dla punktu podanego przez u¿ytkownika
{
	double war = 0.;
	double d = 1.;

	for (int i = 0; i < wezly; i++)
	{
		d = 1.;
		for (int j = 0; j < wezly; j++)
		{
			if (j != i)
				d *= ((podanyPkt - punkt[j].x) / (punkt[i].x - punkt[j].x));
		}
		war += (punkt[i].y * d);
	}

	return war;
}
