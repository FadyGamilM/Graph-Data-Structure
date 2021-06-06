#include "iostream"
#include "vector"
using namespace std;

// Adjacency List Representation..
class Graph
{
private:
   int Vertices;
   // define array of lists, and size isn't defined at compile time, so we will define it using this pointer syntax..
   // Note that the size of this array of lists = |V|, where |V| is number of vertices
   vector<int>*AdjacencyList;
public:
   /****** Constructor ****************/
   Graph( int V){
      // set number of vertices..
      this->Vertices=V;
      // now number of vertices is known, so we can set the size of our array of lists
      this->AdjacencyList=new vector<int>[V];
   }
   /************************************/

   /**************  Add Edge Function *********************/
   void add_Edge(int first_vertix, int second_vertix ){
      // Construct/Link the edge between first and second vertix by adding the second_vertix in the AdjacencyList of first_vertix
      AdjacencyList[first_vertix].push_back(second_vertix);
      // Construct/Link the edge between second and first vertix by adding the first_vertix in the AdjacencyList of second_vertix
      AdjacencyList[second_vertix].push_back(first_vertix);
   }  
   /*********************************************************/
};



int main(){
   return 0;
}
