#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <stack>
#include <fstream>
#include <memory>
#include <stdexcept>
using namespace std;

namespace Hacker
{
    struct Attribute
    {
        string name;
        string value;
        Attribute(string name, string value)
        {
            this->name = name;
            this->value = value;
        }
    };

    template<class A, class B> struct NodeWithChildren
    {
        A head;
        vector<B> body;
        NodeWithChildren(A name) : head(name) {};
        NodeWithChildren(A name, vector<B> body) : head(name), body(body) {};
    };

    typedef NodeWithChildren<string, Attribute> Tag;

    typedef NodeWithChildren<Tag, Tag> Node;

    class TreeWithArbitraryNoOfNodes
    {
    	struct Nod
		{
			Tag NodeTag;
			vector<shared_ptr<Nod>> NodeChildren;

    	};

    	shared_ptr<Nod> root;
    	stack<shared_ptr<Nod>> pile;
    public:
    	bool hasChildren() {return (root->NodeChildren.size() > 0);}
    	void process(string& line)
		{
			// cout << "In function process with input " << line << endl;
			// detect if line is an opening/closing tag
			auto l = line.length();
			if (l < 3)
				throw length_error("parsing line isn't long enough\n");
			auto init = line[1];
			if (init == '/')
			{
				//closing tag
				// string closingTag{copy(line[2], line[line.length() - 2], closingTag)};
				// cout << "\t" << "closing tag encountered; stack contains" << pile.size() << " elements\n";
				pile.pop();
			}
			else
			{
				// starting tag
				// cout << "\t" << "starting tag encountered\n";
				string data(begin(line) + 1, end(line) - 1);
				// cout << "\t" << data << endl;
				auto elements{splitByToken(data, ' ')};
				// print_vector(elements);
				Tag tag(elements[0]); // tag created with name specified
				for (size_t i = 1; i < elements.size(); i++)
				{
					if (elements[i].find('=') != string::npos) // delimiter between attribute name and attribute value
						tag.body.push_back
						(
							Attribute
							(
								elements[i - 1],
								string(begin(elements[i + 1]) + 1, end(elements[i + 1]) - 1)
							)
						);
				} //up to this point tag with attributes is created
				shared_ptr<Nod> newNod = shared_ptr<Nod>(new Nod{tag,{}});
				auto parentNod = pile.top();
				parentNod->NodeChildren.push_back(newNod);
				pile.push(newNod);
			}
			// cout << "call to process function has terminated \n";
		}

		string extractQuery(string& data)
		{
			// return "__dummy implem__";
			string query{"Not Found!"};
			// cout << "call to extractQuery <" << data << ">\n";
			auto currentNode = root;
			auto elements{splitByToken(data, '~')};
			// print_vector(elements);
			auto tags = splitByToken(elements[0], '.');
			// print_vector(tags);
			for (int i = 0; i < tags.size(); i++)
			{
				for (auto item = begin(currentNode->NodeChildren);;item++)
				{
					if (item == end(currentNode->NodeChildren))
						return query;
					else if ((*item)->NodeTag.head == tags[i])
					{
						currentNode = *item;
						break;
					}
				}
			}
			// cout << "\t currentNode is " << currentNode->NodeTag.head;
			for (auto& atributeName : currentNode->NodeTag.body)
				if (atributeName.name.find(elements[1]) != string::npos) {
					query = atributeName.value;
					break;
				}
			return query;
		}

		TreeWithArbitraryNoOfNodes() {
			root = shared_ptr<Nod>{new Nod{Tag("root"),{}}};
			pile.push(root);
			// cout << "Root object counts " << root.use_count() << " references\n";
		}
	private:
		// methods
		void print_vector(const vector<string>& elements)
		{
			cout << "\t";
				for (auto& element : elements)
					cout << element << ", ";
					cout << endl;
		}

		vector<string> splitByToken(string& s, char delim)
		{
			vector<string> container;
			stringstream ss{s};
			string item;
			while (getline(ss, item, delim))
			{
				container.push_back(item);
			}
			return container;
		}

    };
} // namespace Hacker

int main() {
    int N, Q;
    string line;
	//    fstream data;
	//    data.open("input.txt", ios::in);
	//    if (!(data.is_open()))
	//    	throw "Input file opening not succeeded!";

    Hacker::TreeWithArbitraryNoOfNodes tree;

    // read N, Q
    // data >> N >> Q;
    // N, Q are read this way; otherwise a blank line is read by getline
    getline(cin, line);
    stringstream in(line);
    in >> N >> Q;
    // cout << N << Q << endl;
    // read hrml source
    for (auto i = 0; i < N; i++)
    {
        getline(cin, line);
        // cout << line << "\n";
        try 
        {
            tree.process(line);
            if (tree.hasChildren() == false)
            	throw range_error("Root node without children nodes");
        } 
        catch (length_error e) 
        {
            cout << "Error: " << e.what() << endl;
            continue;
        }
        catch (range_error e)
        {
        	cout << "Error " << e.what() << endl;
        	continue;
        }
    }

    // process queries
    for (auto i = 0; i < Q; i++)
    {
        string line;
        getline(cin, line);
        cout << tree.extractQuery(line) << endl;
    }
    // data.close();
    return 0;
}
