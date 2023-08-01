#include <iostream>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;


	int i1, i2, i3;
	cin >> i1 >> i2 >> i3;

	int DPs[3] = { i1, i2, i3 };
	int MinDPs[3] = { i1, i2, i3};
	for (int i = 1; i < iN; ++i)
	{
		int i1, i2, i3;
		cin >> i1 >> i2 >> i3;

		int Temp1, Temp2, Temp3;
		if(DPs[0] + i1 < DPs[1] + i1)
			Temp1 = DPs[1] + i1;
		else
			Temp1 = DPs[0] + i1;

		if (DPs[0] + i2 < DPs[1] + i2)
			Temp2 = DPs[1] + i2;
		else
			Temp2 = DPs[0] + i2;
		if (Temp2 < DPs[2] + i2)
			Temp2 = DPs[2] + i2;;

		if (DPs[1] + i3 < DPs[2] + i3)
			Temp3 = DPs[2] + i3;
		else
			Temp3 = DPs[1] + i3;

		DPs[0] = Temp1;
		DPs[1] = Temp2;
		DPs[2] = Temp3;



		if (MinDPs[0] + i1 > MinDPs[1] + i1)
			Temp1 = MinDPs[1] + i1;
		else
			Temp1 = MinDPs[0] + i1;

		if (MinDPs[0] + i2 > MinDPs[1] + i2)
			Temp2 = MinDPs[1] + i2;
		else
			Temp2 = MinDPs[0] + i2;
		if (Temp2 > MinDPs[2] + i2)
			Temp2 = MinDPs[2] + i2;;

		if (MinDPs[1] + i3 > MinDPs[2] + i3)
			Temp3 = MinDPs[2] + i3;
		else
			Temp3 = MinDPs[1] + i3;

		MinDPs[0] = Temp1;
		MinDPs[1] = Temp2;
		MinDPs[2] = Temp3;

	}

	int iTempNum = max(DPs[0], DPs[1]);
	iTempNum = max(iTempNum, DPs[2]);
	cout << iTempNum << " ";

	iTempNum = min(MinDPs[0], MinDPs[1]);
	iTempNum = min(iTempNum, MinDPs[2]);
	cout << iTempNum;


	return 0;
}