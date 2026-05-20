def twoSum(nums, target):
    prev_map = {}
    
    for i, n in enumerate(nums):
        diff = target - n
        
        if diff in prev_map:
            return [prev_map[diff], i]
        
        prev_map[n] = i
    
    return []

def main():
    nums = [2, 7, 11, 15]
    target = 9
    print(f"indexes: {twoSum(nums, target)}")

if __name__ == "__main__":
    main()
