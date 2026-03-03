
//2026,xiangyin zhan
//{图}

//无向图的节点定义如下：
//无向图的节点

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/************************************************************************************
//Clone Graph

描述

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbours.
OJ's undirected graph serialization:
Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbour of the node.
As an example, consider the serialized graph {{0,1,2#1,2#2,2}}.
The graph has a total of three nodes, and therefore contains three parts as separated by #.

 1.First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 2.Second node is labeled as 1. Connect node 1 to node 2.
 3.Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
//Visually, the graph looks like the following:
//       1
//      / \
//     /   \
//    0 --- 2
//         / \
//         \_/

//分析
//广度优先遍历或深度优先遍历都可以。
//DFS

//Leetcode, Clone Graph
//DFS,时间复杂度 O(n),空间复杂度O(n)
*************************************************************************************/
class Solution {
    public:
    UndirectedGraphNode *cloneGraph(const UndirectedGraphNode *node){
        if(node == nullptr) return nullptr;
        //key is original node,value is copied node
        unordered_map<const UndirectedGraphNode *,
                            UndirectedGraphNode *> copied;
        clone(node, copied);
        return copied[node];
    }

    private:
    //DFS
    static UndirectedGraphNode* clone(const UndirectedGraphNode *node,
    unordered_map<const UndirectedGraphNode *,
    UndirectedGraphNode *> &copied) {
        //a copy already exists
        if (copied.find(node) != copied.end()) return copied[node];

        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        copied[node] = new_node;
        for(suto nbr : node->neighbors)
            new_node->neighbors.push_back(clone(nbr, copied));
        return new_node;
    }
};


/************************************************************************************
BFS
//LeetCode, Clone Graph
//BFS, 时间复杂度O(n)，空间复杂度O(n)

class Solution{
public:
        UndirectedGraphNode *cloneGraph(const UndirectedGraphNode *node){
            if(node == nullptr) return nullptr;
            //key is original node,value is copied node
            unordered_map<const UndirectedGraphNode *,
            UndirectedGraphNode *> copied;
            //each node is queue is already copied itself
            //but neighbors are not copied yet
            queue<const UndirectedGraphNode *> q;
            q.push(node);
            copied[node] = new UndirectedGraphNode(node->label);
            while (!q.empty()){
                const UndirectedGraphNode *cur = q.front();
                q.pop();
                for (auto nbr : cur->neighbors) {
                    //a copy already exists
                    if(copied.find(nbr) != copied.end()){
                        copied[cur]->neighbors.push_back(copied[nbr]);
                    }else{
                        UndirectedGraphNode *new_nnode = 
                                    new UndirectedGraphNode(nbr->label);
                            copied[nbr] = new_node;
                            copied[cur]->neighbors.push_back(new_node);
                            q.push(nbr);
                    }
                }
            }
            return coupied[node];
        }
};

************************************************************************************/



