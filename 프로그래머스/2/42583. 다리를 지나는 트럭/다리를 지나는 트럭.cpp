#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Temps[10001] = { 0 };

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;

    int Sum = 0;
    int Index = 0;
    while (true)
    {
        ++answer;
        
        Sum -= Temps[0];
        Temps[0] = 0;

        for (int i = 1; i < bridge_length; ++i)
        {
            Temps[i - 1] = Temps[i];
        }
        Temps[bridge_length - 1] = 0;
    

        // 올라가야할 트럭이 있다
        if (Index < truck_weights.size())
        {
            // 무게 확인
            if (Sum + truck_weights[Index] > weight)
            {
                continue;
            }
            else
            {
                Sum += truck_weights[Index];
                Temps[bridge_length - 1] = truck_weights[Index];

                Index++;
            }
        }
        // 올라가야할 트럭이 없고, 올라간 트럭도 없다
        else if(Sum == 0)
        {
            break;
        }

    }
    

    return answer;
}