#include "iostream"
#include "vector"
// we will use hash-map as data structure to the list of each vertex..
#include "unordered_map"
using namespace std;

// Adjacency List Representation..
class Graph
{
private:
   int Vertices;
   /*
         A->D
         | \ / |
         | / \ |
         B   C
               " This is a list of pairs<string, int> "   
         A-> [(D,50), (C,10), (B,20)]
         B-> [(A,20), (D.30)]
         C-> [(A,10), (D,40)]
         D-> [(C,40), (B,30)] ** note that we didn't write its edge with A
   */
   unordered_map<string,vector<pair<string,int>>> Adjacency_List;

public:
   /****** Constructor ****************/
   Graph( int V){
      // set number of vertices..
      this->Vertices=V;
      // now number of vertices is known, so we can set the size of our array of lists
      //this->Adjacency_List=new unordered_map<string, vector<>>[V];
   }
   /************************************/

   /**************  Add Edge Function *********************/
   void add_Edge(string first_vertex, string second_vertex, bool is_biDierctional, int weight ){
      // Construct/Link the edge between first and second vertix by adding the second_vertix in the AdjacencyList of first_vertix
      this->Adjacency_List[first_vertex].push_back(make_pair(second_vertex,weight));
      // if it's a bi-dierctional edge, we have to put the first_vetex in the list of second_vertex..
      if(is_biDierctional){
      // Construct/Link the edge between second and first vertix by adding the first_vertix in the AdjacencyList of second_vertix
      this->Adjacency_List[second_vertex].push_back(make_pair(first_vertex,weight));
      }
   }  
   /*********************************************************/

   /**************  Iterate through all vertices *********************/
   void print_Ajdacency_List(){
      for(auto Item : this->Adjacency_List){ // each item is pair of <vertex,[AdjenecyList]>
         string vertex_name=Item.first;
         cout<<vertex_name<<"  --> ";
         vector<pair<string,int>> connected_vertcies=Item.second;
         for(auto connected_vertex:connected_vertcies){ //where connected_vertcies is a list of pairs and each pair is <String,int>
            cout<<connected_vertex.first<<", ";
         } 
         cout<<endl;
      }
   }
   /******************************************************************/
};



int main(){
   Graph G1(4);
   G1.add_Edge("A","B",true,20);
   G1.add_Edge("A","D",false,50);
   G1.add_Edge("A","C",true,10);
   G1.add_Edge("B","D",true,40);
   G1.add_Edge("C","D",true,30);
   G1.print_Ajdacency_List();
   return 0;
}
