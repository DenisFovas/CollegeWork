from Graph.graph_class import DirectedGraph, BFSsearch
from ui.console import Console

if __name__ == "__main__":
    graph = DirectedGraph()
    app = Console(graph, "sample.txt")
    print("Please wait until the file reading has finished!")
    app.run()