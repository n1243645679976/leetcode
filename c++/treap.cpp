namespace chh{
    class TreapNode{
    public:
      int data, sum;
      long long priority;
      int subtreesize;
      array<TreapNode*, 2> kids;
      TreapNode(int d, long long pr) : data(d), sum(d), priority(pr), subtreesize(1), kids({NULL, NULL}) {}
      void recalc(){
        sum = data;
        subtreesize = 1;
        if(kids[0]) sum += kids[0]->sum, subtreesize += kids[0]->subtreesize;
        if(kids[1]) sum += kids[1]->sum, subtreesize += kids[1]->subtreesize;
      }
    };
    class TreapTree{
    public:
      int n;
      TreapNode* root;
      vector<TreapNode*> nodes;
      TreapTree(vector<int>& arr) : n(arr.size()), nodes(arr.size()) {
        for(int i=0;i<n;i++) nodes[i] = new TreapNode(arr[i], rnd(gen));
        root = nodes[0];
        for(int i=1;i<n;i++) root = merge(root, nodes[i]);
      }
      // checked : https://codeforces.com/gym/102787/submission/315296857
      array<TreapNode*, 2> split(TreapNode* node, int leftsize){
        if(!node) return {NULL, NULL};
        if(leftsize == 0) return {NULL, node};
        if(node->kids[0] && leftsize <= node->kids[0]->subtreesize){
          auto [left, right] = split(node->kids[0], leftsize);
          node->kids[0] = right;
          node->recalc();
          return {left, node};
        }
        else{
          int sz = leftsize - (node->kids[0] ? node->kids[0]->subtreesize : 0) - 1;
          auto [left, right] = split(node->kids[1], sz);
          node->kids[1] = left;
          node->recalc(); 
          return {node, right};
        }
      }
      // checked : https://codeforces.com/gym/102787/submission/315296857
      TreapNode* merge(TreapNode* left, TreapNode* right){
        if(!left) return right;
        if(!right) return left;
        // keep the relative position, if add right, then try add left to right's left subtree (leave full right's right subtree).
        if(left->priority > right->priority){
          right->kids[0] = merge(left, right->kids[0]);
          right->recalc();
          return right;
        }
        else{
          left->kids[1] = merge(left->kids[1], right);
          left->recalc();
          return left;
        }
      }
      void printdfs(TreapNode* node){
        if(!node) return ;
        if(node->kids[0]) printdfs(node->kids[0]);
        cout<<node->data<<" ";
        if(node->kids[1]) printdfs(node->kids[1]);
      }
      void printnode(TreapNode* node){ // DLR
        printdfs(node);
        cout<<endl;
      }
    };
  }