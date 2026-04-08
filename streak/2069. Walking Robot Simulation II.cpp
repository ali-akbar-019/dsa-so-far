class Robot
{
public:
    int idx = 0;
    vector<vector<int>> pos;
    bool moved = false;
    Robot(int width, int height)
    {
        // bottom row, left to right ->East[0]
        for (int x = 0; x < width; x++)
        {
            pos.push_back({x, 0, 0});
        }
        // right col, bottom to up -> North[1]
        for (int y = 1; y < height; y++)
        {
            pos.push_back({width - 1, y, 1});
        }
        // top row , right to left -> West[2]
        for (int x = width - 2; x >= 0; x--)
        {
            pos.push_back({x, height - 1, 2});
        }
        // left col, top to bottom -> South[3]
        for (int y = height - 2; y > 0; y--)
        {
            pos.push_back({0, y, 3});
        }
        // edge case jab wo start ho raha to 0,0, E par agar wapas waha aya to fir waha hona chahie south
        pos[0][2] = 3; // filhal me use south kar raha , edge case ko neche handle karu ga
    }

    void step(int num)
    {
        moved = true;
        idx = (idx + num) % pos.size();
    }

    vector<int> getPos()
    {
        return {pos[idx][0], pos[idx][1]};
    }

    string getDir()
    {
        // edge case
        // agar movement keya hi nahi ha to
        if (!moved)
        {
            return "East";
        }
        //
        int dir = pos[idx][2];
        if (dir == 0)
        {
            return "East";
        }
        else if (dir == 1)
        {
            return "North";
        }
        else if (dir == 2)
        {
            return "West";
        }
        else
        {
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */