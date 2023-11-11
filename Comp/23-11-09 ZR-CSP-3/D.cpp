#include <iostream>
#include <map>
#include <limits>
#include <queue>

using i64 = long long;

namespace FastIO {

    class FastIOBase
    {
    protected:
    #ifdef OPENIOBUF
        static const int BUFSIZE=1<<16;
        char buf[BUFSIZE+1];
        int buf_p=0;
    #endif
        FILE *target;
        FastIOBase(FILE *f): target(f){}
        ~FastIOBase()=default;
    public:
    #ifdef OPENIOBUF
        virtual void flush()=0;
    #endif
    };

    class FastOutput final: public FastIOBase
    {
    private:
        void __putc(char x)
        {
    #ifdef OPENIOBUF
            if(buf[buf_p++]=x,buf_p==BUFSIZE) flush();
    #else
            putc(x,target);
    #endif
        }
        template<typename T>
        void __write(T x)
        {
            char stk[std::numeric_limits<T>::digits10+1],*top=stk;
            if(x<0) return __putc('-'),__write(-x);
            do *(top++)=x%10,x/=10; while(x);
            for(;top!=stk;__putc(*(--top)+'0'));
        }
    public:
        FastOutput(FILE *f=stdout): FastIOBase(f) {}
    #ifdef OPENIOBUF
        ~FastOutput() { flush(); }
        void flush() { fwrite(buf,1,buf_p,target),buf_p=0; }
    #endif
        FastOutput &operator <<(char x)
        { return __putc(x),*this; }
        FastOutput &operator <<(const char *s)
        { for(;*s;__putc(*(s++)));return *this; }
        FastOutput &operator <<(const std::string &s)
        { return (*this)<<s.c_str(); }
        template<typename T>
        std::enable_if_t<std::is_integral<T>::value,FastOutput&> operator <<(const T &x)
        { return __write(x),*this; }
        template<typename ...T>
        void writesp(const T &...x)
        { std::initializer_list<int>{(this->operator<<(x),__putc(' '),0)...}; }
        template<typename ...T>
        void writeln(const T &...x)
        { std::initializer_list<int>{(this->operator<<(x),__putc('\n'),0)...}; }
        template<typename Iter>
        void writesp(Iter begin,Iter end)
        { while(begin!=end) (*this)<<*(begin++)<<' '; }
        template<typename Iter>
        void writeln(Iter begin,Iter end)
        { while(begin!=end) (*this)<<*(begin++)<<'\n'; }
    }qout;

    class FastInput final: public FastIOBase
    {
    private:
        bool __eof;
    public:
        FastInput(FILE *f=stdin): FastIOBase(f),__eof(false)
    #ifdef OPENIOBUF
        { buf_p=BUFSIZE; }
        void flush() { buf[fread(buf,1,BUFSIZE,target)]=EOF,buf_p=0; }
        bool eof()const { return buf[buf_p]==EOF; }
    #else
        {}
        bool eof()const { return feof(target); }
    #endif
        char get()
        {
            if(__eof) return EOF;
    #ifdef OPENIOBUF
            if(buf_p==BUFSIZE) flush();
            char ch=buf[buf_p++];
    #else
            char ch=getc(target);
    #endif
            return ~ch?ch:(__eof=true,EOF);
        }
        void unget(char c)
        {
            __eof=false;
    #ifdef OPENIOBUF
            buf[--buf_p]=c;
    #else
            ungetc(c,target);
    #endif
        }
        explicit operator bool()const { return !__eof; }
        FastInput &operator >>(char &x)
        { while(isspace(x=get()));return *this; }
        template<typename T>
        std::enable_if_t<std::is_integral<T>::value,FastInput&> operator >>(T &x)
        {
            char ch,sym=0;x=0;
            while(isspace(ch=get()));
            if(__eof) return *this;
            if(ch=='-') sym=1,ch=get();
            for(;isdigit(ch);x=(x<<1)+(x<<3)+(ch^48),ch=get());
            return unget(ch),sym?x=-x:x,*this;
        }
        FastInput &operator >>(char *s)
        {
            while(isspace(*s=get()));
            if(__eof) return *this;
            for(;!isspace(*s) && !__eof;*(++s)=get());
            return unget(*s),*s='\0',*this;
        }
        FastInput &operator >>(std::string &s)
        {
            char str_buf[(1<<8)+1]={0},*p=str_buf;
            char *const buf_end=str_buf+(1<<8);
            while(isspace(*p=get()));
            if(__eof) return *this;
            for(s.clear(),p++;;p=str_buf)
            {
                for(;p!=buf_end && !isspace(*p=get()) && !__eof;p++);
                if(p!=buf_end) break;
                s.append(str_buf);
            }
            unget(*p),*p='\0',s.append(str_buf);
            return *this;
        }
        template<typename ...T>
        void read(T &...x)
        { std::initializer_list<int>{(this->operator>>(x),0)...}; }
        template<typename Iter>
        void read(Iter begin,Iter end)
        { while(begin!=end) (*this)>>*(begin++); }
    }qin;

} // namespace FastIO
using FastIO::qin;
using FastIO::qout;

const int maxn = 100005;

int n, Q;

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

namespace Subtask1 {
    int siz[maxn], son[maxn], fa[maxn], dep[maxn];
    void tree_build (int now) {
        siz[now] = 1;
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa[now]) { continue; }

            fa[t] = now;
            dep[t] = dep[now] + 1;
            tree_build (t);
            siz[now] += siz[t];
            if (siz[t] > siz[son[now]]) { son[now] = t; }
        }
    }

    int top[maxn], dfn[maxn], dpos, bottom[maxn];
    void tree_decomp (int now, int topnow) {
        dfn[now] = ++dpos;
        bottom[now] = dfn[now];
        top[now] = topnow;

        if (not son[now]) { return; }
        
        tree_decomp (son[now], topnow);
        bottom[now] = std::max (bottom[now], bottom[son[now]]);

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa[now]) { continue; }
            if (t == son[now]) { continue; }

            tree_decomp (t, t);
            bottom[now] = std::max (bottom[now], bottom[t]);
        }
    }

    template <int size, typename val_t>
    struct BIT {
        val_t tr[size];

        inline int lowbit (int x) { return x & (-x); }

        inline void modify (int pos, val_t val) { for (int i = pos; i <= dpos; i += lowbit (i)) { tr[i] += val; } }
        inline val_t _query (int pos) { val_t res = 0; for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; } return res; }

        inline val_t query (int l, int r) { return _query (r) - _query (l - 1); }
    };

    BIT<maxn, i64> tr;

    inline i64 subtreeQuery (int u) { return tr.query (dfn[u], bottom[u]); }

    inline void init () {
        dep[0] = 1;
        tree_build (1);
        tree_decomp (1, 1);
    }

    inline void addStore_dfs (int now, int fa, i64 p, i64 delta) {
        if (not delta) { return; }
        tr.modify (dfn[now], delta);

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) { continue; }

            addStore_dfs (t, now, p, delta / p);
        }        
    }

    i64 lazy_delta = 0;
    inline void addStore (int u, i64 w, i64 p) { // 操作1
        if (p == 1) { lazy_delta += w; return; }        
        addStore_dfs (u, 0, p, w);
    }

    inline std::pair<i64, i64> queryRoad (int u, int v) {
        bool swap_flag = false;
        if (dep[u] < dep[v]) { std::swap (u, v); swap_flag = true; }

        i64 ans_u = subtreeQuery (u) + siz[u] * lazy_delta;
        i64 ans_v = subtreeQuery (1) - subtreeQuery (u) + (n - siz[u]) * lazy_delta;

        if (swap_flag) { std::swap (ans_u, ans_v); }
        
        return std::pair<i64, i64> { ans_u, ans_v };
    }

    inline void solve () {
        init ();

        while (Q--) {
            int op; qin >> op;
            if (op == 1) {  
                int u; qin >> u;
                i64 w, p; qin >> w >> p;
                addStore (u, w, p);
            } else if (op == 2) {
                int u, v; qin >> u >> v;
                auto res = queryRoad (u, v);
                qout << res.first << " " << res.second << "\n";
            }
        }
    }
}

/*
    自己想出来的神秘bdfs
    但是存在一些更神秘的问题
    (似乎是某些地方id和bfn没有处理好)
*/

namespace Subtask2 {

    // 纵剖
    int siz[maxn], son[maxn], fa[maxn], dep[maxn];
    void treeBuild (int now) {
        siz[now] = 1;
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa[now]) { continue; }

            fa[t] = now;
            dep[t] = dep[now] + 1;
            treeBuild (t);
            siz[now] += siz[t];
            if (siz[t] > siz[son[now]]) { son[now] = t; }
        }
    }

    int top[maxn], dfn[maxn], dpos, bottom[maxn];
    void treeDecomp (int now, int topnow) {
        dfn[now] = ++dpos;
        top[now] = topnow;
        bottom[now] = dfn[now];

        if (not son[now]) { return; }

        treeDecomp (son[now], topnow);
        bottom[now] = std::max (bottom[now], bottom[son[now]]);

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa[now]) { continue; }
            if (t == son[now]) { continue; }

            treeDecomp (t, t);
            bottom[now] = std::max (bottom[now], bottom[t]);
        }
    }

    inline void init () {
        dep[1] = 1;
        treeBuild (1);
        treeDecomp (1, 1);
    }

    bool inSubtree (int x, int u) {
        return dfn[x] >= dfn[u] and dfn[x] <= bottom[u];
    }

    int left_son[maxn];
    int bfn[maxn], bpos;
    int dep_r[maxn];

    struct BFSNode {
        int now;
        int dep;
    };

    void bfs () {
        std::queue<BFSNode> q;
        q.push (BFSNode { 1, 1 });
        
        while (not q.empty ()) {
            int now = q.front ().id;
            int now_dep = q.front ().dep;
            q.pop ();

            bfn[now] = ++bpos;
            step_r[step_now] = bfn[now];

            left_son[now] = es[last[now]].v;

            for (int i = last[now]; i; i = es[i].pre) {
                int t = es[i].v;
                if (t == fa[now]) { continue; }

                q.push (BFSNode { t, now_dep + 1 });
            }
        }
    }

    inline int getRightSon (int now, int u) {
        int l = bfn[now];
        int r = dep_r[dep[now]];

        int res = 0;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (inSubtree (mid, u)) { l = mid + 1; res = mid; }
            else { r = mid - 1; }
        }

        return res;
    }

    template<int size, typename val_t>
    struct SegmentTree {
        struct Node {
            val_t sum;
            val_t tag;
            bool cov;
        } tr[size << 3];

        inline void pushUp (int now) { tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum; }

        inline void update (int now, int l, int r, val_t val) {
            tr[now].sum += val * (r - l + 1);
            tr[now].cov = true;
            tr[now].tag = val;
        }

        inline void pushDown (int now, int l, int r) {
            if (not tr[now].cov) { return; }
            int mid = (l + r) >> 1;
            pushDown (now << 1, l, mid, tr[now].tag);   
            pushDown (now << 1 | 1, mid + 1, r, tr[now].tag);
            tr[now].cov = false;
            tr[now].tag = 0;
        }

        void modify (int now, int l, int r, int L, int R, val_t val) {
            if (L <= l and r <= R) { update (now, l, r, val); }

            pushDown (now, l, r);

            int mid = (l + r) >> 1;
            if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
            if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }
            
            pushUp (now);
        }

        val_t query (int now, int l, int r, int L, int R) {
            if (L <= l and r <= R) { return tr[now].sum; }
            
            pushDown (now, l, r);
            
            val_t res = 0;

            int mid = (l + r) >> 1;
            if (L <= mid) { res += query (now << 1, l, mid, L, R); }
            if (R > mid) { res += query (now << 1 | 1, mid + 1, r, L, R); }

            return res;
        }
    };

    Tree <maxn, i64> tr;

    void addStore (i64 u, i64 w, i64 p) {
        tr.modify (1, 1, n, bfn[u], bfn[u], w);
        
        i64 delta = w / p;

        int fa_now = fa[u];
        int son_now = left_son[u];
        while (delta) {
            int right_son = getRightSon (son_now, u);

            tr.modify (1, 1, n, bfn[u], bfnpu)

            delta /= p;
            fa_now = fa[fa_now];
            son_now = left_son[son_now];
        }
    }   

    inline void solve () {
        
    }

}


int main () {

    qin >> n >> Q;
	
    for (int i = 1; i <= n - 1; i++) {
        int u, v; qin >> u >> v;
        addEdge (u, v); addEdge (v, u);
    }

    Subtask1::solve ();

    return 0;
}