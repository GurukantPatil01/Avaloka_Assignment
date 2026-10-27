class Solution {
public:
    bool can_attend_all(vector<pair<int, int>>& events) {
        sort(events.begin(), events.end());

        for (int i = 1; i < events.size(); i++) {
            if (events[i].first < events[i - 1].second) {
                return false;
            }
        }

        return true;
    }

    int min_rooms_required(vector<pair<int, int>>& events) {
        vector<int> start_times, end_times;

        for (auto event : events) {
            start_times.push_back(event.first);
            end_times.push_back(event.second);
        }

        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int start = 0, end = 0;
        int rooms = 0, max_rooms = 0;
        int n = events.size();

        while (start < n) {
            if (start_times[start] < end_times[end]) {
                rooms++;
                max_rooms = max(max_rooms, rooms);
                start++;
            } else {
                rooms--;
                end++;
            }
        }

        return max_rooms;
    }
};
