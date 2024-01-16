#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

std::unordered_map<std::string, std::vector<std::string>> makeGraph(std::vector<std::tuple<std::string, std::string>> edges) {
  std::unordered_map<std::string, std::vector<std::string>> graph;
  
  for (auto edge: edges) {
    auto [a,b] = edge;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  return graph;
}

int shortestPath(std::vector<std::tuple<std::string, std::string>> edges, std::string nodeA, std::string nodeB) {
  std::unordered_map<std::string, std::vector<std::string>> graph = makeGraph(edges);
  
  std::queue<std::tuple<std::string, int>> queue;
  std::unordered_set<std::string> visited;
  queue.push(std::tuple<std::string, int> {nodeA, 0});
  visited.insert(nodeA);
  
  while (queue.size() > 0) {
    auto [currentNode, distance] = queue.front();
    queue.pop();
    
    if (currentNode == nodeB) {
      return distance;
    }
    
    for (std::string neighbor: graph[currentNode]) {
      if (visited.count(neighbor) == 0) {
        visited.insert(neighbor);
        queue.push(std::tuple<std::string, int> {neighbor, distance + 1});
      }
    }
  } 
  
  return -1;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
