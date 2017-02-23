#include <vector>
#include <string>
#include <array>

using namespace std;

class Algorithm {
  private array cacheServers;

  public Algorithm(array cacheServers){cacheServers = cacheServers}

  public function getHighestScoreCacheServer(int currentRequestLd, int numberOfRequest, array currentRequestLc)
  {
    int cacheId = 0;
    int i=0;
    int maxValue = 0;
    
    for( i=0; i <= sizeof(cacheServers); i++)
    {
        value = (currentRequestLd - currentRequestLc[i])*numberOfRequest;
        
        if(value > maxValue){
            cacheId = i;
        }
    }

    return cacheId;
  }
}
