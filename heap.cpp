#include<iostream>
using namespace std;
//class for heap
class BinaryHeap{
    public:
	//pointer to the array
	int *hArr;
	//maximum size
	int mSize;
	//current size
	int cSize;
	
	//**************************************************************************
	
	//constructer
	BinaryHeap(int mSize){
		hArr = new int[mSize];
		this->mSize = mSize;
		cSize = 0;
	}
	//**************************************************************************
	void swap(int *a,int *b){
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	//**************************************************************************
	int left(int i){ return (i*2)+1;}
	int right(int i){ return (i*2)+2;}
	int parent(int i){ return (i-1)/2;}
	
	int get_min(){return hArr[0];}
	//**************************************************************************
	void insert(int value){
		//when overflowed
		if(cSize == mSize){
			cout<<"noT possible"<<endl;
			return;
		}
		else{
			//inserting new value;
			hArr[cSize] = value;
			//ensuring the rule is carried over
			int i = cSize;
			while(i!=0 && hArr[parent(i)]>hArr[i]){
				swap(&hArr[parent(i)],&hArr[i]);
				i = parent(i);
			}
			//incresing the cSize
			cSize++;
		}
	}
	
	//**************************************************************************
	void display(){
		for(int i = 0; i < cSize; i++){
			cout<<hArr[i]<<",";
		}
		cout<<endl;
	}
	
	//**************************************************************************
	void MinHeapify(int i){
		int smallest;
		if(left(i),right(i)<cSize){
			if(hArr[left(i)]<hArr[i]){
				smallest = left(i);
			}
			if(hArr[right(i)]<hArr[smallest]){
				smallest = right(i);
			}
			if(smallest!=i){
				swap(&hArr[smallest],&hArr[i]);
			}
			MinHeapify(smallest);
		}
		else return;
	}
	
	
	//**************************************************************************
	int ExtractMin(int i){
		if(cSize == 0){
			cout<<"No sufficient elements"<<endl;
		}
		else if(cSize == 1){
			cSize = 0;
		}
		else{
			swap(&hArr[i],&hArr[cSize-1]);
			MinHeapify(i);
			return hArr[i];
		}
	}
	int ExtractMin(){
		return ExtractMin(0);
	}
	//**************************************************************************
	void decreaseKey(int i,int new_value){
		if(i<cSize){
			hArr[i] = new_value;
			while(i!=0 && hArr[parent(i)]>hArr[i]){
				swap(&hArr[parent(i)],&hArr[i]);
				i = parent(i);
			}
		}
		else cout<<"Not possible";
	}
	//**************************************************************************
	void deleteAt(int i){
		decreaseKey( i,hArr[get_min()]);
		ExtractMin(i);
	}
	//**************************************************************************

	
};
int main(){
    BinaryHeap bh1(20);
    int n;
    for(int i = 10; i >0 ; i--){
        cout << "Inserting "<<i<<endl; //cin>>n;
        bh1.insert(i);
        bh1.display();
    }
}
