class Solution {
public:
    bool canChange(string start, string target) {

        if (start.length() != target.length())
            return false;

        int startFreq[3] = {0};
        int targetFreq[3] = {0};

        for (int i = 0; i < start.size(); i++) {
            if (start[i] == '_')
                startFreq[0]++;
            else if (start[i] == 'L')
                startFreq[1]++;
            else if (start[i] == 'R')
                startFreq[2]++;
        }

        for (int i = 0; i < target.size(); i++) {
            if (target[i] == '_')
                targetFreq[0]++;
            else if (target[i] == 'L')
                targetFreq[1]++;
            else if (target[i] == 'R')
                targetFreq[2]++;
        }

        if (startFreq[0] != targetFreq[0] || startFreq[1] != targetFreq[1] ||
            startFreq[2] != targetFreq[2])
            return false;

        int i = 0, j = 0;
        while (i < start.size() && j < target.size()) {

            while (i < start.size() && start[i] == '_')
                i++;
            while (j < target.size() && target[j] == '_')
                j++;

            if (i == start.size() || j == target.size())
                break;

            if (start[i] == 'L' && target[j] == 'L') {

                if (j > i)
                    return false;
            } else if (start[i] == 'R' && target[j] == 'R') {

                if (i > j)
                    return false;
            } else if (start[i] != target[j]) {
                return false;
            }

            i++;
            j++;
        }

        return true;
    }
};
