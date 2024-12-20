#include "astar.h"

/**
 * @brief Construct a new Node:: Node object
 * 
 * @param heuristic 
 */
Node::Node(double heuristic)
{
    costEstimatedToGoal = heuristic;
}

/**
 * @brief Construct a new Node:: Node object
 * 
 */
Node::Node()
{
    for (int dx = 1; dx >= -1; dx--)
        for (int dy = 1; dy >= -1; dy--)
        {
            if (dx == 0 && dy == 0)
                continue;
            Node::direction.push_back(make_pair(dx, dy));
        }
}

/**
 * @brief Construct a new Node:: Node object
 * 
 * @param x 
 * @param y 
 */
Node::Node(double x, double y)
{

    costToThisNode = 0;
    costEstimatedToGoal = 0;
    findIndexForMap = false;
    actionToThisNode.reserve(10000);
    path.reserve(10000);
    findIndex(x, y);
    //path.push_back(make_pair(xIndexAtMap,yIndexAtMap));
    // cout << xIndexAtMap << "," << yIndexAtMap << endl;
}
// initializing first Node

/**
 * @brief 
 * 
 * @param nowX 
 * @param nowY 
 */
void Node::findIndex(double nowX, double nowY)
{
    for (int y = 0; y < 100; y++)
    {
        for (int x = 0; x < 100; x++)
        {
            if (fabs(Node::mapInformation[x][y].x - nowX) < 0.05 && fabs(Node::mapInformation[x][y].y - nowY) < 0.05)
            {
                xIndexAtMap = x;
                yIndexAtMap = y;
                findIndexForMap = true;
                break;
            }
        }
        if (findIndexForMap)
            break;
    }
}

/**
 * @brief Construct a new Node:: Node object
 * 
 * @param x 
 * @param y 
 * @param directionToHere 
 * @param pathCost 
 * @param heuristic 
 * @param fromWhere 
 */
Node::Node(double x, double y, vector<int> directionToHere, double pathCost, double heuristic, vector<pair<int, int>> fromWhere)
{
    xIndexAtMap = x;
    yIndexAtMap = y;
    actionToThisNode = directionToHere;
    costToThisNode = pathCost;
    costEstimatedToGoal = costToThisNode + heuristic;
    path = fromWhere;
}
//initializing new node

/**
 * @brief 
 * 
 */
void Node::setMap()
{
    if (!Node::mapBuilt)
    {
        file = fopen("/home/louis/map.csv", "w+");
        file2 = fopen("/home/louis/obstacle.csv", "w+");
        for (int y = 0; y < 100; y++)
            for (int x = 0; x < 100; x++)
            {
                double x_position = -5 + x * Node::distanceBetweenNode;
                double y_position = -5 + y * Node::distanceBetweenNode;
                Node::mapInformation[x][y].x = x_position;
                Node::mapInformation[x][y].y = y_position;
            }
        fprintf(file, "\n");
        fprintf(file2, "\n");
    }
    Node::mapBuilt = 1;
}

bool Node::costComparator(const Node nodeA, const Node nodeB)
{
    return nodeA.costEstimatedToGoal > nodeB.costEstimatedToGoal;
}


/**
 * @brief 
 * 
 * @param nowNode 
 * @param goal_x 
 * @param goal_y 
 * @return vector<Node> 
 */
vector<Node> Node::getSuccessor(Node nowNode, double goal_x, double goal_y)
{
    int nextX;
    int nextY;
    int which_direction = 1;
    double cost;
    vector<Node> result;
    result.reserve(8);
    double heuristicCost;
    for (auto it = Node::direction.begin(); it != Node::direction.end(); it++)
    {
        nextX = nowNode.xIndexAtMap + it->first;
        nextY = nowNode.yIndexAtMap + it->second;
        if ((nextX < 100 && nextX >= 0) && (nextY < 100 && nextY >= 0))
        {
            if (!Node::mapInformation[nextX][nextY].obstacleExist)
            {
                Node::expandCount++;
                cost = pow(pow(it->first / 10.0, 2) + pow(it->second / 10.0, 2), 0.5);
                heuristicCost = ChebyshevHeuristic(Node::mapInformation[nextX][nextY].x,
                                                   Node::mapInformation[nextX][nextY].y, goal_x, goal_y);
                vector<int> act = nowNode.actionToThisNode;
                if (!act.empty())
                {
                    if (*(act.end() - 1) != which_direction)
                        //heuristicCost += (45 / 360) * 2 * M_PI / 10;
                        heuristicCost *= 1.005;
                }
                vector<pair<int, int>> fromWhere = nowNode.path;
                fromWhere.push_back(make_pair(nextX, nextY));
                act.push_back(which_direction);
                Node *nodePtr = new Node(nextX, nextY, act, nowNode.costToThisNode + cost, heuristicCost, fromWhere);
                result.push_back(*nodePtr);
            }
        }
        which_direction++;
    }
    return result;
}

/**
 * @brief 
 * 
 * @param goal_x 
 * @param goal_y 
 */
void Node::showMap(double goal_x, double goal_y)
{
    for (int y = 99; y >= 0; y--)
        for (int x = 0; x <= 99; x++)
        {
            pair<int, int> printWhere = make_pair(x, y);
            auto temp = find(path.begin(), path.end(), printWhere);
            if (temp == path.end())
            {
                if (Node::mapInformation[x][y].obstacleExist)
                    printf("x");
                else
                    printf(".");
            }
            else
            {
                if (!isGoal(Node::mapInformation[x][y].x, Node::mapInformation[x][y].y, goal_x, goal_y))
                    printf("*");
                else
                    printf("!");
            }
        }
    printf("\n");
}

/**
 * @brief 
 * 
 * @param initX 
 * @param initY 
 * @param goalX 
 * @param goalY 
 * @return Node 
 */
Node Node::findPath(double initX, double initY, double goalX, double goalY)
{
    priority_queue<Node, vector<Node>, decltype(&Node::costComparator)> pq(Node::costComparator);
    bool visited[100][100];
    memset(visited, 0, 100 * 100);
    Node startNode(initX, initY);
    pq.push(startNode);
    clock_t start = clock();
    while (!pq.empty())
    {
        Node nowNode = pq.top();
        pq.pop();
        if (!isGoal(Node::mapInformation[nowNode.xIndexAtMap][nowNode.yIndexAtMap].x, Node::mapInformation[nowNode.xIndexAtMap][nowNode.yIndexAtMap].y, goalX, goalY))
        {
            if (!visited[nowNode.xIndexAtMap][nowNode.yIndexAtMap])
            {
                Node::nodeVisitedAmount++;
                visited[nowNode.xIndexAtMap][nowNode.yIndexAtMap] = true;
                auto successors = getSuccessor(nowNode, goalX, goalY);
                for (auto it : successors)
                    if (!visited[it.xIndexAtMap][it.yIndexAtMap])
                        pq.push(it);
            }
        }
        else
        {
            nowNode.path.push_back(make_pair(nowNode.xIndexAtMap, nowNode.yIndexAtMap));
            clock_t end = clock();
            cout << "time cost = " << (double)(end - start) / CLOCKS_PER_SEC << endl;
            cout << "expand count = " << Node::expandCount << endl;
            cout << "node visited = " << Node::nodeVisitedAmount << endl;
            for (auto it = nowNode.actionToThisNode.begin(); it != nowNode.actionToThisNode.end(); it++)
            {
                cout << *it;
                if (it != nowNode.actionToThisNode.end() - 1)
                    cout << "->";
            }
            cout << endl;
            int qq = 0;
            for (auto it = nowNode.path.begin(); it != nowNode.path.end(); it++)
            {
                cout << "(" << it->first << "," << it->second << ")";
                if (it != nowNode.path.end() - 1)
                    cout << "->";
            }
            cout << endl;
            nowNode.showMap(goalX, goalY);
            int count = 0;

            return nowNode;
        }
    }
}

/**
 * @brief 
 * 
 * @param index 
 * @return vector<pair<double, double>> 
 */
vector<pair<double, double>> Node::indexToMap(vector<pair<int, int>> index)
{
    vector<pair<double, double>> toMap;
    toMap.reserve(1000);
    for (auto it = index.begin(); it != index.end(); it++)
    {
        toMap.push_back(make_pair(Node::mapInformation[it->first][it->second].x, Node::mapInformation[it->first][it->second].y));
    }
    return toMap;
}

/**
 * @brief 
 * 
 * @param originMap 
 * @return vector<pair<int, int>> 
 */
vector<pair<int, int>> Node::refineMap(vector<pair<int, int>> originMap)
{
    double slope = 0;
    int previousY = 0;
    int previousX = 0;
    double previousSlope = 0;
    for (auto it = originMap.begin(); it != originMap.end();)
    {
        slope = (it->second - previousY) / (it->first - previousX);
        previousY = it->second;
        previousX = it->first;
        if (slope == previousSlope)
        {
            auto deleteLater = it++;
            originMap.erase(deleteLater);
        }
        else
        {
            it++;
            previousSlope = slope;
        }
    }
    return originMap;
}

/**
 * @brief 
 * 
 * @param originAct 
 * @return vector<int> 
 */
vector<int> Node::refineDirection(vector<int> originAct)
{
    int previousAct = 0;
    for (auto it = originAct.begin(); it != originAct.end();)
    {
        if (*it == previousAct)
        {
            auto deleteLater = it++;
            originAct.erase(it);
        }
        else
        {
            it++;
            previousAct = *it;
        }
    }
    return originAct;
}
