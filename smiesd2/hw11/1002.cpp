// ²ßÂÔÄ£Ê½

/*
#include <iostream>

#include <string>

using namespace std;
 
struct TaoBaoItem
{
	int price;
	int volume_of_sales;
};
 
class SortInterface
{
public:
	virtual ~SortInterface() {};
	virtual void DoSort(TaoBaoItem item[], int size) = 0;
};
*/
class SortByPrice : public SortInterface
{
public:
	virtual void DoSort(TaoBaoItem item[], int size);
};

void SortByPrice::DoSort(TaoBaoItem item[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (item[j].price < item[j + 1].price)
			{
				TaoBaoItem tmp = item[j];
				item[j] = item[j + 1];
				item[j + 1] = tmp;
			}
		}
	}
}

class SortBySales : public SortInterface
{
public:
	virtual void DoSort(TaoBaoItem item[], int size);
};

void SortBySales::DoSort(TaoBaoItem item[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (item[j].volume_of_sales < item[j + 1].volume_of_sales)
			{
				TaoBaoItem tmp = item[j];
				item[j] = item[j + 1];
				item[j + 1] = tmp;
			}
		}
	}
}


class TaoBao
{
public:
	TaoBao(SortInterface* strategy);
	void SetSortStrategy(SortInterface* strategy);
	// Use current strategy_ to do the sort.
	void sort(TaoBaoItem item[], int size);
private:
	SortInterface *strategy_;
};

TaoBao::TaoBao(SortInterface* strategy)
{
	strategy_ = strategy;
}

void TaoBao::SetSortStrategy(SortInterface* strategy)
{
	strategy_ = strategy;
}

void TaoBao::sort(TaoBaoItem item[], int size)
{
	strategy_->DoSort(item, size);
}

/*
void printItem(TaoBaoItem arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i].price << " " << arr[i].volume_of_sales << endl;
}
 
int main(int argc, char *argv[])
{
	TaoBaoItem item[4] = {
		{1, 2},
		{2, 3},
		{5, 1},
		{3, 10}
	};
	SortByPrice price;
	SortBySales sales;
 
	TaoBao taobao(&price); 
	taobao.sort(item, 4);
	printItem(item, 4);
	
	taobao.SetSortStrategy(&sales);
	taobao.sort(item, 4);
	printItem(item, 4);
 
	return 0;
}
*/