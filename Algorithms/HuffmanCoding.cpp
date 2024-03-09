/*
Yes, that's correct. The Huffman codes are generated based on the characters present in the given string used to build the Huffman tree

The frequencies of characters in that particular string are considered, and Huffman codes are generated accordingly.
If you want to encode a different string, you would need to build a new Huffman tree based on that string, and the codes would be generated specifically for the characters in that string.


Huffman coding is a widely used algorithm for lossless data compression.
* Frequency Counting -The first step is to analyze the input data and count the frequency of each character
* Priority Queue (Min-Heap):Each unique character is then treated as a node and placed in a priority queue (min-heap) based on its frequency.The nodes with the lowest frequencies have the highest priority in the queue.
* Building the Huffman Tree: 
* Assigning Codes: The Huffman tree is traversed to assign binary codes to each character. Moving left in the tree appends a '0' to the code, and moving right appends a '1'.
* Generating Huffman Codes: The binary codes assigned to each character constitute the Huffman codes. These codes are unique and have the property that no code is a prefix of another. This property ensures unambiguous decoding
* Encoding: The input data is encoded by replacing each character with its corresponding Huffman code.
* Decoding: The encoded data can be efficiently decoded using the Huffman tree

Huffman coding is widely used in applications like file compression (ZIP and GZIP formats), image compression (JPEG), and various communication protocols. It provides a way to represent data more efficiently by allocating shorter codes to more frequent symbols, resulting in overall compression of the data.

*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class HuffmanNode
{
public:
    char data;
    unsigned frequency;
    HuffmanNode *left, *right;

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

class HuffmanTree
{
private:
    HuffmanNode *root;

    // Comparison function for priority queue
    struct CompareNodes
    {
        bool operator()(HuffmanNode *const &lhs, HuffmanNode *const &rhs) const
        {
            return lhs->frequency > rhs->frequency;
        }
    };

    void buildTree(const string &text)
    {
        // Count the frequency of each character
        unordered_map<char, unsigned> freqMap;
        for (char c : text)
        {
            freqMap[c]++;
        }

        // Create a priority queue of nodes
        priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNodes> pq;
        for (auto &pair : freqMap)
        {
            pq.push(new HuffmanNode(pair.first, pair.second));
        }

        // Build the Huffman tree
        while (pq.size() > 1)
        {
            HuffmanNode *left = pq.top();
            pq.pop();

            HuffmanNode *right = pq.top();
            pq.pop();

            HuffmanNode *internalNode = new HuffmanNode('$', left->frequency + right->frequency);
            internalNode->left = left;
            internalNode->right = right;

            pq.push(internalNode);
        }

        // Set the root of the Huffman tree
        root = pq.top();
    }

    void generateCodes(HuffmanNode *node, string code, unordered_map<char, string> &huffmanCodes) const
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->data != '$')
        {
            huffmanCodes[node->data] = code;
        }

        generateCodes(node->left, code + "0", huffmanCodes);
        generateCodes(node->right, code + "1", huffmanCodes);
    }

public:
    HuffmanTree(const string &text) : root(nullptr)
    {
        buildTree(text);
    }

    ~HuffmanTree()
    {
        // Clean up memory
        // You may use a destructor or another mechanism to handle memory deallocation.
        // For simplicity, we are not including that here.
    }

    unordered_map<char, string> getHuffmanCodes() const
    {
        unordered_map<char, string> huffmanCodes;
        generateCodes(root, "", huffmanCodes);
        return huffmanCodes;
    }

    string encode(const string &text) const
    {
        unordered_map<char, string> huffmanCodes = getHuffmanCodes();
        string encodedText = "";
        for (char c : text)
        {
            encodedText += huffmanCodes.at(c);
        }
        return encodedText;
    }

    string decode(const string &encodedText) const
    {
        string decodedText = "";
        HuffmanNode *current = root;

        for (char bit : encodedText)
        {
            if (bit == '0')
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }

            if (current->left == nullptr && current->right == nullptr)
            {
                decodedText += current->data;
                current = root;
            }
        }

        return decodedText;
    }
};

int main()
{
    string text = "Huffman coding is a compression algorithm.";

    HuffmanTree huffmanTree(text);

    unordered_map<char, string> huffmanCodes = huffmanTree.getHuffmanCodes();

    for (auto &pair : huffmanCodes)
    {
        cout << pair.first << " " << pair.second << endl;
    }

    string encodedText = huffmanTree.encode(text);
    cout << "Encoded text: " << encodedText << endl;

    string decodedText = huffmanTree.decode(encodedText);
    cout << "Decoded text: " << decodedText << endl;

    return 0;
}
