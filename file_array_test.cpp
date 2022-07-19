#include <iostream>
using namespace std;


int main()
{

  int array1[] = {10,2,5,4,10,5,6,9,8,10};
  int array2[10];

  int array2_elements_inserted = 0; 

  for(int i = 0; i < 10; i++)
    {
      int temp = array1[i];

      bool isDuplicate = false; 
      for(int j = 0; j < array2_elements_inserted; j++)
        {
          if(temp == array2[j])
            {
              cout << "Duplicate " << temp << endl;
              isDuplicate = true; 
              break;
            }
        }

      if (!isDuplicate)
        {
          array2[array2_elements_inserted] = temp;
          ++array2_elements_inserted; 
        }
    }

    for(int k = 0; k < array2_elements_inserted; k++)
        cout << array2[k] << "  " << endl;
  //  system("pause");
}