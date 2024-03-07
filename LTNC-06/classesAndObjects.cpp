

// Write your Student class here
class Student {
    private:
        vector<int> scores;
    public:
        void input() {
            for (int i = 0; i < 5; i++) {
                int tmp; cin >> tmp;
                scores.push_back(tmp);
            }
        }
        int calculateTotalScore() {
            int sum = 0;
            for (int score : scores) {
                sum += score;
            }
            return sum;
        }
};
