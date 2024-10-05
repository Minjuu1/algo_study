from collections import deque
def solution(bridge_length, weight, truck_weights):
    time = 0
    truck_weights = deque(truck_weights)
    bridge = deque([0] * bridge_length)
    w = 0
    while(bridge):
        time += 1
        w -= bridge.popleft()
        if truck_weights:
            if w + truck_weights[0] <= weight:
                truck = truck_weights.popleft()
                bridge.append(truck)
                w += truck
            else:
                bridge.append(0)
    return time