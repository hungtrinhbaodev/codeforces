#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#include <thread>
#include <chrono>
#include <ctime>
#define ll long long
#define INF -1
#define NONE_VALUE -1

struct Node {
    int index = INF;
    ll final_value = NONE_VALUE;
    ll step_value = NONE_VALUE;
    // two child node
    std::vector<Node*> child_nodes;
};

bool is_leaf_node(Node *node) {
    return node->child_nodes.size() <= 0;
}

void print_node(Node *node) {
    std::cout << "------------" << std::endl;
    std::cout << "node info: " << std::endl;
    std::cout << "node index: " << node->index + 1 << std::endl;
    std::cout << "node final value: " << node->final_value << std::endl;
    std::cout << "node step value: " << node->step_value << std::endl;
    if (is_leaf_node(node)) {
        std::cout << "node leaf!"<<std::endl;
    } 
    else {
        std::cout << "node children indices: " << node->child_nodes[0]->index << ", " << node->child_nodes[1]->index << std::endl;
    }
}

void make_graph( 
    int n,
    int m,
    std::vector<Node*> &graph, 
    std::vector<std::vector<int>> &queries,
    std::vector<Node*> &final_node_at_indices,
    std::vector<ll> &final_value_at_indices
) {
    // init graph with n base node
    for (size_t i = 0; i < n; i++) {
        Node *p_node = new Node();
        p_node->index = i;
        graph.push_back(p_node);
        final_node_at_indices[i] = p_node;
    }

    for(size_t i = 0; i < m; i++) {
        int child_one_index = queries[i][0];
        int child_two_index = queries[i][1];
        int parent_index = queries[i][2];

        // get two child node index pointer at index 
        Node *last_node_one = final_node_at_indices[child_one_index];
        Node *last_node_two = final_node_at_indices[child_two_index];

        // create new node with 2 child
        Node *p_node = new Node();
        p_node->index = parent_index;
        p_node->child_nodes.push_back(last_node_one);
        p_node->child_nodes.push_back(last_node_two);

        // update final node at final node index array
        final_node_at_indices[parent_index] = p_node;

        // add new node to graph
        graph.push_back(p_node);
    }

    // fill final value for node in graph by final node index array
    for (size_t i = 0; i < final_node_at_indices.size(); i++) {
        Node *p_node = final_node_at_indices[i];
        int final_value = final_value_at_indices[i];
        p_node->final_value = final_value;
    }
}

bool update_child_nodes_value(Node *parent, std::vector<Node*> &childrens) {
    if (is_leaf_node(parent)) return true;

    Node *child_one = childrens[0];
    Node *child_two = childrens[1];
    switch (parent->final_value) {
        case NONE_VALUE: {
            switch (parent->step_value) {
                case NONE_VALUE: {
                    return true;
                }
                default: {
                    if (child_one->final_value != NONE_VALUE && child_two->final_value != NONE_VALUE) {
                        return true;
                    }
                    else if (child_one->final_value == NONE_VALUE && child_two->final_value == NONE_VALUE) {
                        if (child_one->step_value < parent->step_value) {
                            child_one->step_value = parent->step_value;
                        }
                        if (child_two->step_value < parent->step_value) {
                            child_two->step_value = parent->step_value;
                        }
                    }
                    else {
                        if (child_one->final_value == NONE_VALUE) {
                            int final_child_two_value = child_two->final_value;
                            if (final_child_two_value < parent->step_value) return false;
                            if (child_one->step_value < parent->step_value) {
                                child_one->step_value = parent->step_value;
                            }
                        }
                        else {
                            int final_child_one_value = child_one->final_value;
                            if (final_child_one_value < parent->step_value) return false;
                            if (child_two->step_value < parent->step_value) {
                                child_two->step_value = parent->step_value;
                            }
                        }
                    }
                }
            }
            break;
        }
        default: {
            if (child_one->final_value != NONE_VALUE && child_two->final_value != NONE_VALUE) {
                return parent->final_value == child_one->final_value ||  parent->final_value == child_two->final_value;
            }
            else if (child_one->final_value == NONE_VALUE && child_two->final_value == NONE_VALUE) {
                if (child_one->step_value < parent->final_value) {
                    child_one->step_value = parent->final_value;
                }
                if (child_two->step_value < parent->final_value) {
                    child_two->step_value = parent->final_value;
                }
            }
            else {
                if (child_one->final_value == NONE_VALUE) {
                    int final_child_two_value = child_two->final_value;
                    if (final_child_two_value < parent->final_value) return false;
                    if (final_child_two_value == parent->final_value) {
                        if (child_one->step_value < parent->final_value) {
                            child_one->step_value = parent->final_value;
                        }
                    }
                    else {
                        child_one->final_value = parent->final_value;
                    }
                }
                else {
                    int final_child_one_value = child_one->final_value;
                    if (final_child_one_value < parent->final_value) return false;
                    if (final_child_one_value == parent->final_value) {
                        if (child_two->step_value < parent->final_value) {
                            child_two->step_value = parent->final_value;
                        }
                    }
                    else {
                        child_two->final_value = parent->final_value;
                    }
                }
            }
            break;
        }
    }
    return true;
}

bool verify_ans(
    int n,
    int m,
    std::vector<ll> &final_ans_values, 
    std::vector<ll> &final_value_at_indices,
    std::vector<std::vector<int>> &queries
) {
    std::vector<ll> tmp_final_values = final_ans_values;
    for (size_t i = 0; i < m; i++) {
        int child_one_index = queries[i][0];
        int child_two_index = queries[i][1];
        int parent_index = queries[i][2];

        ll value_one = tmp_final_values[child_one_index];
        ll value_two = tmp_final_values[child_two_index];

        tmp_final_values[parent_index] = value_one < value_two ? value_one : value_two;
    }

    for (size_t i = 0; i < n; i++) {
        if (tmp_final_values[i] != final_value_at_indices[i]) return false;
    }

    return true;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::vector<std::vector<int>> queries;
        std::vector<Node *> graph;
        std::vector<Node *> final_node_at_indices;
        std::vector<ll> final_value_at_indices;
        std::vector<ll> final_ans_values;

        int n, m;
        std::cin >> n >> m;

        final_value_at_indices.resize(n);
        final_node_at_indices.resize(n);
        final_ans_values.resize(n);
        queries.resize(m);

        for (size_t i = 0; i < n; i++) {
            ll final_value;
            std::cin >> final_value;
            final_value_at_indices[i] = final_value;
        }

        for (size_t i = 0; i < m; i++) {
            int child_one_index, child_two_index, parent_index;
            std::cin >> child_one_index >> child_two_index >> parent_index;
            queries[i] = std::vector<int>{
                child_one_index - 1, 
                child_two_index - 1, 
                parent_index - 1
            };
        }

        make_graph(
            n, m,
            graph,
            queries,
            final_node_at_indices,
            final_value_at_indices
        );

        bool is_finish_update = true;
        for (int i = graph.size() - 1; i > -1; i--) {
            if (!update_child_nodes_value(
                graph[i],
                graph[i]->child_nodes
            )) {
                is_finish_update = false;
                break;
            }
        }

        if(!is_finish_update) {
            std::cout << -1 << std::endl;
            continue;
        }
        
        for (size_t i = 0; i < n; i++) {
            Node *p_node = graph[i];
            switch (p_node->final_value) {
                case NONE_VALUE: {
                    final_ans_values[i] = p_node->step_value;
                    break;
                }
                default: {
                    final_ans_values[i] = p_node->final_value;
                    break;
                }
            }
        }

        bool is_verify_success = verify_ans(
            n, m,
            final_ans_values,
            final_value_at_indices,
            queries
        );

        if (!is_verify_success) {
            std::cout << -1 << std::endl;
            continue;
        }

        for (size_t i = 0; i < n; i++) {
            ll final_value = final_ans_values[i];
            if (final_value == NONE_VALUE) final_value = 1;
            std::cout << final_value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2116/problem/D
 */
