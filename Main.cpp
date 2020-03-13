//Main
#include "Header.h"
void main()
{
	int choice;
	cout << " 1) Vector \n"
		" 2) Matrix \n";
	(cin >> choice).get();

	if (choice == 1)
	{
		setlocale(LC_ALL, ("UKR"));
		srand(time(0));
		/////////
		Vector<int> vect(5), vect2(5); int sw; bool run = true;
		vect.Menu();
		do
		{
			cout << "\n\n Enter : ";
			(cin >> sw).get();
			switch (sw)
			{
			case 0:
			{
				run = false;
				break;
			}
			case 1:
			{
				vect.SetVector();
				break;
			}
			case 2:
			{
				vect.PrTVector();
				break;
			}
			case 3:
			{
				vect.AddEnd();
				break;
			}
			case 4:
			{
				vect.AddStart();
				break;
			}
			case 5:
			{
				cout << "\n Enter a poTer position : ";
				(cin >> sw).get();
				vect.AddNeedPosition(sw);
				break;
			}
			case 6:
			{
				vect.DeleteStart();
				break;
			}
			case 7:
			{
				vect.DeleteEnd();
				break;
			}
			case 8:
			{
				cout << "\n Enter a poTer position : ";
				(cin >> sw).get();
				vect.DeleteNeedPosition(sw);
				break;
			}
			case 9:
			{
				vect.DeleteVector();
				break;
			}
			case 10:
			{
				cout << vect.GetMaxElement() << "\n";
				break;
			}
			case 11:
			{
				cout << vect.GetMinElement() << "\n";
				break;
			}
			case 12:
			{
				cout << vect.SizeArray() << "\n";
				break;
			}
			case 13:
			{
				cout << "\n Enter a poTer position : ";
				(cin >> sw).get();
				cout << vect.GetSearchIndexElement(sw) << "\n";
				break;
			}
			case 14:
			{
				vect.SortGrowth();
				break;
			}
			case 15:
			{
				vect.SortDecrease();
				break;
			}
			case 16:
			{
				vect.Reverse();
				break;
			}
			case 17:
			{
				vect2.SetVector();
				cout << (vect == vect2) << "\n";
				break;
			}
			case 18:
			{
				vect2.SetVector();
				cout << (vect != vect2) << "\n";
				break;
			}
			case 19:
			{
				Vector<int> vect3(5);
				vect2.SetVector();
				vect3 = vect + vect2;
				vect3.PrTVector();
				break;
			}
			case 20:
			{
				cout << " Enter index : ";
				(cin >> sw).get();
				vect[sw];
				break;
			}
			case 21:
			{
				cout << " Enter number : ";
				(cin >> sw).get();
				vect(sw);
				break;
			}
			case 22:
			{
				cout << " Enter number : ";
				(cin >> sw).get();
				vect.Left(sw);
				break;
			}
			case 23:
			{
				cout << " Enter number : ";
				(cin >> sw).get();
				vect.Right(sw);
				break;
			}
			case 24:
			{
				cout << vect << "\n";
				break;
			}
			case 25:
			{
				cin >> vect;
				break;
			}
			}
		} while (run);
		/////////
	}
	else if (choice == 2)
	{
		srand(time(0));
		///////////
		int sw, rows = 3, cols = 3, number; bool run = true;
		Matrix<int> matrix(rows, cols);
		Vector<int>* v2;
		Vector<int> v(cols);

		matrix.Menu();

		do
		{
			(cin >> sw).get();
			switch (sw)
			{
			case 0:
			{
				run = false;
				break;
			}
			case 1:
			{
				matrix.Set();
				break;
			}
			case 2:
			{
				matrix.PrT();
				break;
			}
			case 3:
			{
				v.SetVector();
				matrix.AddEndLine(v);
				break;
			}
			case 4:
			{
				v.SetVector();
				matrix.AddStartLine(v);
				break;
			}
			case 5:
			{
				cout << "\n Enter position : ";
				(cin >> sw).get();

				v.SetVector();
				matrix.AddSpecifiedPosition(sw, v);
				break;
			}
			case 6:
			{
				cout << "\n Enter position : ";
				(cin >> sw).get();
				cout << "\n Enter number rows : ";
				(cin >> number).get();

				CreateVectorS(v2, number, cols);
				SetVectorS(v2, number);
				matrix.AddFewLinesToThePosition(sw, number, v2);
				break;
			}
			case 7:
			{
				matrix.DeleteEndLine();
				break;
			}
			case 8:
			{
				matrix.DeleteFirstLine();
				break;
			}
			case 9:
			{
				matrix.DeleteMatrix();
				break;
			}
			case 10:
			{
				cout << "\n Enter position : ";
				(cin >> sw).get();
				matrix.DeleteSpecifiedPosition(sw);
				break;
			}
			case 11:
			{
				cout << "\n Enter position : ";
				(cin >> sw).get();
				cout << "\n Enter number rows : ";
				(cin >> number).get();

				matrix.DeleteFewLinesFromSpecifiedPosition(sw, number);
				break;
			}
			case 12:
			{
				matrix.AddColumnEnd();
				break;
			}
			case 13:
			{
				matrix.AddColumnStart();
				break;
			}
			case 14:
			{
				cout << "\n Enter position : ";
				(cin >> sw).get();
				matrix.AddColumnToTheSpecifiedPosition(sw);
				break;
			}
			case 15:
			{
				cout << "\n Enter position : ";
				(cin >> sw).get();
				cout << "\n Enter number cols : ";
				(cin >> number).get();

				matrix.AddMultipleColumnSpecifiedPosition(sw, number);
				break;
			}
			case 16:
			{
				matrix.DeleteColumnEnd();
				break;
			}
			case 17:
			{
				matrix.DeleteColumnStart();
				break;
			}
			case 18:
			{
				cout << "\n Enter position : ";
				(cin >> sw).get();
				matrix.DeleteColumnSpecifiedPosition(sw);
				break;
			}
			case 19:
			{
				cout << "\n Enter position : ";
				(cin >> sw).get();
				cout << "\n Enter number cols : ";
				(cin >> number).get();

				matrix.DeleteMultipleColumnFromTheSpecifiedPosition(sw, number);
				break;
			}
			case 20:
			{
				cout << "\n Enter position : ";
				(cin >> sw).get();
				cout << matrix.SearchMaxElement(sw) << "\n";;
				break;
			}
			case 21:
			{
				cout << "\n Enter position : ";
				(cin >> sw).get();
				cout << matrix.SearchMinElement(sw) << "\n";;
				break;
			}
			case 22:
			{
				cout << matrix.SearchMaxElementOfAllArray() << "\n";
				break;
			}
			case 23:
			{
				cout << matrix.SearchMinElementOfAllArray() << "\n";
				break;
			}
			case 24:
			{
				cout << "\n Enter position : ";
				(cin >> sw).get();
				matrix.SortsLineAtTheSpecifiedPositionForGrowth(sw);
				break;
			}
			case 25:
			{
				cout << "\n Enter position : ";
				(cin >> sw).get();
				matrix.SortsLineAtTheSpecifiedPositionForDecrease(sw);
				break;
			}
			case 26:
			{
				matrix.SortAllLinesForGrowth();
				break;
			}
			case 27:
			{
				matrix.SortAllLinesForDecrease();
				break;
			}
			case 28:
			{
				matrix.ReverseAllLines();
				break;
			}
			case 29:
			{
				matrix.ReverseAllColumn();
				break;
			}
			case 30:
			{
				cout << "\n How many add rows? ";
				(cin >> rows).get();
				cout << "\n How many columns do I add ? ";
				(cin >> cols).get();

				matrix.ExpandsArray(rows, cols);
				break;
			}
			case 31:
			{
				matrix.TransposeTheMatrix();
				break;
			}
			case 32:
			{
				cout << "\n Enter number : ";
				(cin >> sw).get();
				matrix.Left(sw);
				break;
			}
			case 33:
			{
				cout << "\n Enter number : ";
				(cin >> sw).get();
				matrix.Right(sw);
				break;
			}
			}
		} while (run);
		///////////
	}
}