// Que :- Repeat and Missing Number

// https://www.youtube.com/watch?v=5nMGY4VUoRY&list=PLgUwDviBIf0rPG3Ictpu74
// YWBQ1CaBkm2&index=3 

// Solution :

// 1st Brute
// hint :- short the array and use index to find the missing element (simple brute force)
// Time -> O(nlogn) , Space -> O(1)

// 2nd Better
// hint :- using extra space and in O(n) time 
//         use hash table and mark the element that occur once as (1) and if the element occur again (repeating) then output that 
//         and in secound travel check the unmarked element and output that as not occuring element .
// Time -> O(n) , space -> O(n) 

// 3rd Best
// hint :- Traverse the array. While traversing, use the absolute value of every element as an index and make the value at this 
//         index as negative to mark it visited. If something is already marked negative then this is the repeating element.
//         To find missing, traverse the array again and look for a positive value.
        
//  Code :-
 class solution {
 public :
      void print_two_element(int arr[] ,  int size){
            cout << "The repeating element is -> ";
            
            for(int i =0; i < size; i++){
                  if(arr[abs(arr[i])-1] > 0){
                      arr[abs(arr[i] -1)] = -arr[abs(arr[i]-1)];
                  }
                  else {
                      cout << abs(arr[i]) <<endl;
                  }
            }
            
            for (int i =0; i<size ; i++){
                  if(a[i] >0) cout <<(i+1)<<endl; 
            }
      }
 };

// 4th Best 
// hint  :- use the xor property and deep understanding of xor operations

void solve() {

    int a[6] = {4, 3, 6, 2, 1, 1};
    //we have to find the missing and the repeating number in the array

    int x = 0, y = 0;
    fr(i, 0, 5) {
        x = x ^ a[i];
    }
    fr(i, 1, 6) {
        y = y ^ i;
    }
    int num = x ^ y;

    vi k, m;
    int set_bit = num & ~(num - 1);

    fr(i, 1, 6) {
        if (set_bit & i) { // do not use the comparision with (set_bit & i  != 0 )
                            // it will give wrong ans
            k.pb(i);
        }
        else m.pb(i);
    }

    fr(i, 0, 5) {
        if (set_bit & a[i]) {
            k.pb(a[i]);
        }
        else m.pb(a[i]);
    }
    int l = 0, n = 0;
    fr(i, 0, k.size() - 1) {
        l = l ^ k[i];
    }

    fr(i, 0, m.size() - 1) {
        n = n ^ m[i];
    }
    // cout <<n<<" "<<l;
    bool f =0;
    fr(i,0,5){
        // bool f =0;
        if(n == a[i]){
            f=1;
        } // n is repeating and the other is  missing  

    }
    if(f){
        cout << "repeating no is " <<n<<endl;
        cout <<"non repeating no is "<<l<<endl;
    }
    else {
        cout << "repeating no is " <<l<<endl;
        cout <<"non repeating no is "<<n<<endl;        
    }
}
