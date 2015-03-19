class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer
    def compareVersion(self, version1, version2):
        version1 = [int(item) for item in version1.split('.')]
        version2 = [int(item) for item in version2.split('.')]
        diff = len(version1) - len(version2)
        if diff > 0:
            for i in range(diff):
                version2.append(0)
        else:
            for i in range(abs(diff)):
                version1.append(0)
        
        if version1 > version2:
            return 1
        elif version1 < version2:
            return -1
        else:
            return 0