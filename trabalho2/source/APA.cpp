#include "../include/Graph.hpp"
#include "defines.hpp"

bool Graph::fecho(const size_t node_id)
{
    Node* vertice = this->get_node(node_id);
    if(vertice == nullptr)
    {
        std::cout << "fecho\n  Erro: não foi encontrado " << node_id << " no grafo\n  Retornando false...\n";
        return false;
    }
    
    // cria map para os nos marcados
    std::unordered_map<size_t, char> marcado;
    for(Node* node = this->first_node; node != nullptr; node = node->next_node)
        marcado[node->id] = ' ';

    this->fecho_aux(node_id, vertice, marcado);

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

void Graph::fecho_fraco_aux(size_t node_id,const std::unordered_map<size_t, std::vector<size_t>>& adj_simetrica, std::unordered_map<size_t, char>& marcado)
{
    marcado[node_id] = '*';

    if (adj_simetrica.count(node_id)) {
        for (const auto& vizinho_id : adj_simetrica.at(node_id)) {
            if (marcado[vizinho_id] != '*') {
                this->fecho_fraco_aux(vizinho_id, adj_simetrica, marcado);
            }
        }
    }
}
bool Graph::verifica_conectividade_fraca()
{
    ///Caso para grafo vazio
    if (this->first_node == nullptr) {
        std::cout << "O grafo esta vazio." << std::endl;
        return true;
    }
    // Cria a lista de adjacências simétrica
    std::unordered_map<size_t, std::vector<size_t>> adj_simetrica;
    for (Node* node = this->first_node; node != nullptr; node = node->next_node)
    {
        adj_simetrica[node->id];
        for (Edge* edge = node->first_edge; edge != nullptr; edge = edge->next_edge)
        {
            adj_simetrica[edge->origin_id].push_back(edge->target_id);
            adj_simetrica[edge->target_id].push_back(edge->origin_id);
        }
    }
    // Inicializa marcado com ' '.
    std::unordered_map<size_t, char> marcado;
    for(Node* node = this->first_node; node != nullptr; node = node->next_node) {
        marcado[node->id] = ' ';
    }
    // Executa a busca em profundidade a partir do primeiro nó
    this->fecho_fraco_aux(this->first_node->id, adj_simetrica, marcado);
    // Verifica o vetor marcado, se algum não esta marcado com '*', o grafo não desconexo
    //se todos foram marcados, o grafo é fracamente conexo
    for(const auto& [id, marca] : marcado) {
        if(marca == ' ') {
            return false;
        }
    }
    return true;
}