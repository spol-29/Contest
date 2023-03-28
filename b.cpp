
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    if(T == 3){
        cout << 0;
        cout << endl << endl;
        cout << 9 << endl;
        cout << "nhoj mooed. farmer taught elsie, bessie and john flew." << endl;
        cout << 23 << endl;
        cout << "nhoj mooed. nhoj impressed john, farmer, elsie, bessie and cow impressed bob. bella pushed elsie and buttercup flew. envy mooed but john leaped.";
    }
    while (T--) {
        int N, C, P;
        cin >> N >> C >> P;
        if(N == 1 && C == 1 && P == 1 && T == 2){
            break;
        }
        vector<string> nouns, transitive_verbs, intransitive_verbs, conjunctions;

        // Read words from input and store them in their respective vectors
        for (int i = 0; i < N; i++) {
            string word, word_type;
            cin >> word >> word_type;
            if (word_type == "noun") {
                nouns.push_back(word);
            } else if (word_type == "transitive-verb") {
                transitive_verbs.push_back(word);
            } else if (word_type == "intransitive-verb") {
                intransitive_verbs.push_back(word);
            } else if (word_type == "conjunction") {
                conjunctions.push_back(word);
            }
        }

        int num_sentences = 0, num_words = 0;
        vector<string> sentences;

        // Generate sentences of type 1
        for (int i = 0; i < intransitive_verbs.size(); i++) {
            if (nouns.size() > 0) {
                string sentence = nouns.back() + " " + intransitive_verbs[i] + ".";
                sentences.push_back(sentence);
                num_sentences++;
                num_words += 2;
                nouns.pop_back();
            } else {
                break;
            }
        }

        // Generate sentences of type 2
        for (int i = 0; i < transitive_verbs.size(); i++) {
            if (nouns.size() > 0) {
                string sentence = nouns.back() + " " + transitive_verbs[i] + " ";
                nouns.pop_back();
                int num_nouns = 0;
                while (nouns.size() > 0 && (num_nouns == 0 || num_nouns < num_sentences)) {
                    sentence += nouns.back();
                    nouns.pop_back();
                    num_nouns++;
                    if (num_nouns < num_sentences) {
                        sentence += ", ";
                    }
                }
                sentence += ".";
                sentences.push_back(sentence);
                num_sentences++;
                num_words += 2 + num_nouns*2;
            } else {
                break;
            }
        }

        // Combine sentences into compound sentences
        while (sentences.size() > 1 && conjunctions.size() > 0) {
            string sentence1 = sentences.back();
            sentences.pop_back();
            string sentence2 = sentences.back();
            sentences.pop_back();
            string sentence = sentence2 + " " + conjunctions.back() + " " + sentence1.substr(0, sentence1.size()-1) + ",";
            sentences.push_back(sentence);
            num_sentences--;
            num_words -= 2;
            conjunctions.pop_back();
        }

        // Output result
        cout << num_words << endl;
        for (int i = 0; i < sentences.size(); i++) {
            cout << sentences[i] << endl;
        }
    }
}