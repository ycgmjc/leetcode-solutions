class Solution {
public:
    int sum_of_length(vector<string>& words) {
        int result = 0;
        for(string s : words) {
            result += s.length();
        }
        return result;
    }

    string make_tail(string& s, int w) {
        while(s.length() < w) {
            s += ' ';
        }
        return s;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int index = 0;
        vector<string> line;
        vector<string> result;

        while(index < words.size()) {
            string word = words[index];
            int line_len = sum_of_length(line);

            if(line_len + word.length() + line.size() > maxWidth) {
                if(line.size() == 1) {
                    result.push_back(make_tail(line[0], maxWidth));
                }
                else {
                    int l = line.size();
                    int total_spaces = maxWidth - line_len;
                    int base_spaces = total_spaces / (l - 1);
                    int extra_spaces = total_spaces % (l - 1);

                    string temp = "";
                    
                    for(int i = 0; i < l; i++) {
                        temp += line[i];
                        
                        if(i < l - 1) {
                            int spaces_to_add = base_spaces + (i < extra_spaces ? 1 : 0);
                            temp += string(spaces_to_add, ' ');
                        }
                    }
                    result.push_back(temp);
                }     
                line.clear();           
            }

            line.push_back(word);
            index += 1;
        }   

        if(line.size() > 0) {
            string temp = "";
            for(string s : line) {
                temp += s;
                temp += ' ';
            }
            if(temp.length() > maxWidth) {
                temp.pop_back();
            }
            make_tail(temp, maxWidth);
            result.push_back(temp);
        }

        return result;
    }
};
