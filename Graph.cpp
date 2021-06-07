#include "iostream"
#include "vector"
#include "queue"
#include "stack"
#include "unordered_map"
#include "string"
using namespace std;

template<typename T>
// Adjacency List Representation..
class Graph
{
private:
   int Vertices;
   // define array of lists, and size isn't defined at compile time, so we will define it using this pointer syntax..
   // Note that the size of this array of lists = |V|, where |V| is number of vertices
   //vector<string> *AdjacencyList;
   unordered_map<T,vector<T>> AdjacencyList;
public:
   /****** Constructor ****************/
   Graph( int V){
      // set number of vertices..
      this->Vertices=V;
      // now number of vertices is known, so we can set the size of our array of lists
      //this->AdjacencyList=new vector<string>[V];
   }
   /************************************/

   /**************  Add Edge Function *********************/
   void add_Edge(T first_vertex, T second_vertex ){
      ////===> assume that all edges are bi-dierctional..
      // Construct/Link the edge between first and second vertix by adding the second_vertix in the AdjacencyList of first_vertix
      AdjacencyList[first_vertex].push_back(second_vertex);
      // Construct/Link the edge between second and first vertix by adding the first_vertix in the AdjacencyList of second_vertix
      AdjacencyList[second_vertex].push_back(first_vertex);
   }  
   /*********************************************************/

   /**************  Iterate through all vertices *********************/
   void print_Ajdacency_List(){
      for(auto item:this->AdjacencyList){
         //item : <vertexName:[Adjacency List,.....]>
         cout<<item.first<<" --> ";
         auto Connected_List=item.second;
         for(auto connected_Vertex:Connected_List){
            cout<<connected_Vertex<<", ";
         }
         cout<<endl;
      }
   }
   /******************************************************************/

   /******************* Breadth First Search (BFS) ALgorithm ******************************/
   void BFS(string Start_Vertex){
      // we need 2 additional data structure..
      //==> [1] queue to store on it the connected vertices of current source.
      //==> [2] Visited map that track if this vertex is vistied befor or not.
      unordered_map<T,bool> seen; //[2]
      queue<T> Container; //[1]
      
      /******* Step [1] : Push the given source vertex to queue ********/
      Container.push(Start_Vertex);
      /*******************************************************************/

      /****** Loop untill queue becomes Empty ***********************/
      while(!Container.empty()){
         /******* Step [2] : pop the front vertex from queue ********/
         string Node_to_be_removed=Container.front();
         Container.pop();
         /**************************************************************/

         /*** Step [3] : Process the popped node if it's not seen ***/
         if(seen[Node_to_be_removed]!=true){
            // mark it as seen
            seen[Node_to_be_removed]=true;
            // use the popped node in your functionality, here we will just print it..
            cout<<Node_to_be_removed<<endl;
         }
         /************************************************************/
      
         /*** Step [4] : Add it's unseen childs into the queue ***/
         for(auto connected_vertex:this->AdjacencyList[Node_to_be_removed]){
            // connected_vertex is one of childs of the popped vertex, now check if it's not seen before
            if(seen[connected_vertex]!=true){
               Container.push(connected_vertex);
            }
         }
         /*********************************************************/
      }
   }
   /*******************************************************************************************/

   /******************* Depth First Search (BFS) ALgorithm ******************************/
   /*
      [2]----[1]
        |         |
        |         |
      [3]----[0]<==start 
        |
        |
      [4]----[5]

      visit [0] --> then visit one of it's unvisited childs, 
      so visit [3] --> then visit one of [3]'s unvisited childs,
      so visit [4] --> then visit one of [4]'s unvisited childs,
      so visit [5] --> then visit one of [5]'s unvisited childs,
      No childs to [5] are unvisited anymore because [4] is visited
      so come back to [4], then visit remaining unvisited childs of it,
      but there aren't childs of [4], so comeback to [3]
      and from [3] to [2] and from [2] to [1] and then back from [1] 
      to [2] and back from [2] to [3] and finally back from [3] to [0]
   */
   void DFS(T Start_Vertex,unordered_map<T,bool>&seen){
      seen[Start_Vertex]=true;
      cout<<Start_Vertex<<" ";
      
      for(T connected_vertex:this->AdjacencyList[Start_Vertex]){
         // connected_vertex is one of childs of the popped vertex, now check if it's not seen before
         if(seen[connected_vertex]!=true){
            this->DFS(connected_vertex,seen);
         }
      }
         /*********************************************************************/
   }
  void DFS_Setup_Seen_Structure(T Start_Vertex){ 
      // we need 1 additional data structure..
      //==> [1] Visited map that track if this vertex is vistied befor or not.
      unordered_map<T,bool> seen; 
      // initialize all vertices to be unseen
      for(int i=0;i<this->Vertices;i++){
         seen[i]=false;
      }
      // cal the recursive DFS function that performs the DFS
      this->DFS(Start_Vertex,seen);
  }
};  

int main(){
   Graph<int> G1(6);
   G1.add_Edge(0,3);
   G1.add_Edge(0,1);
   G1.add_Edge(3,4);
   G1.add_Edge(3,2);
   G1.add_Edge(4,5);
   G1.DFS_Setup_Seen_Structure(0);
   return 0;
}
