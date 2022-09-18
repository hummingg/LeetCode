public class Solution {
    public Dictionary<string, SortedList> dic;
    public int FindClosest(string[] words, string word1, string word2) {
        dic = new Dictionary<string, SortedList>();
        for(int i = 0; i < words.Length; ++i){
            if(dic.ContainsKey(words[i])){
                dic[words[i]].Add(i, i);
            }else{
                var sl = new SortedList();
                sl.Add(i, i);
                dic.Add(words[i], sl);
            }
        }
        var idxes1 = dic[word1].Keys;   // .GetEnumerator()
        var idxes2 = dic[word2].Keys;
        // idxes1.Sort();
        // idxes2.Sort();
        // int j = 0, k = 0;
        int ret = int.MaxValue;
        // 归并
        // while(j < idxes1.Count && k < idxes2.Count){
        //     ret = Math.Min(ret, Math.Abs(idxes1[j] - idxes2[k]));
        //     if(ret == 1){
        //         return 1;
        //     }
        //     if(idxes1[j] < idxes2[k]){
        //         ++j;
        //     }else{
        //         ++k;
        //     }
        // }
        // while(true)
        // {
        //     if(idxes1.MoveNext() && idxes2.MoveNext()){

        //     }
        // }
        foreach(int j in idxes1){
            foreach(int k in idxes2){
                int dist = Math.Abs(j - k);
                // if(dist > ret){
                //     break;
                // }
                ret = Math.Min(ret, dist);
            }
        }
        return ret;
    }
}