class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(Encode.find(longUrl) != Encode.end())return "http://" + Encode[longUrl];
        string tmp = "tinyurl.com/" + to_string(Encode.size());//生成tinyURL
        Decode[tmp] = longUrl;
        Encode[longUrl] = tmp;
        return "http://" + tmp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl = shortUrl.substr(7, shortUrl.npos);
        if(Decode.find(shortUrl) != Decode.end()) return Decode[shortUrl];
    }
private:
    unordered_map<string, string> Encode;
    unordered_map<string, string> Decode;
};
