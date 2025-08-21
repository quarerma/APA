#include "../include/Graph.hpp"
#include "defines.h"

bool Graph::fecho()
{
    const size_t first_node_id{this->first_node->id};
    Node* vertice = this->first_node;
    if(vertice == nullptr)
    {
        std::cout << "fecho\n  Erro: não foi encontrado " << first_node_id << " no grafo\n  Retornando false...\n";
        return false;
    }
    
    // cria map para os nos marcados
    std::unordered_map<size_t, char> marcado;
    for(Node* node = this->first_node; node != nullptr; node = node->next_node)
        marcado[node->id] = ' ';

    this->fecho_aux(first_node_id, vertice, marcado);

    for(const auto& [id, marca] : marcado)
        if(marca == ' ')
            return false;
    return true;
}

void Graph::fecho_aux(const size_t node_id, const Node* vertice, std::unordered_map<size_t,char>& marcado)
{
    marcado[vertice->id] = '*';

    auto edges{this->get_edges(node_id)};
    for(const auto& edge : edges)
    {
        size_t w{edge.target_id};
        if(marcado[w] != '*')
            fecho_aux(w, this->get_node(w), marcado);
    }
}

