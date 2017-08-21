# git 使用过程
#### git原理
>Git更像是把变化的文件作快照后，记录在一个微型的文件系统中。每次提交更新时，它会纵览一遍所有文件的指纹信息并对文件作一快照，然后保存一个指向这次快照的索引。为提高性能，若文件没有变化，Git不会再次保存，而只对上次保存的快照作一链接。<br>
Git三种状态：working、staging、git&nbsp;directory<br>
在working中git&nbsp;add-》staging，在使用git&nbsp;commit-》git&nbsp;directory<br>
在working中git&nbsp;clone将库中的工作重新加载下来<br>
#### git配置
>首先在你电脑中生成SSH&nbsp;key(ssh&nbsp;keygen&nbsp;-t&nbsp;ras)将公钥复制到gitlab的SSHkey中。
>>* 1Git全局变量的设置
>>>git&nbsp;config&nbsp;--global&nbsp;user.name&nbsp;"xxx"<br>
   git&nbsp;config&nbsp;--global&nbsp;user.email&nbsp;"xxx@irobsen.com"<br>
>>* 2创建一个新的库
>>>git&nbsp;clone&nbsp;SSH地址<br>
	cd&nbsp;SSH中的地址<br>
	touch&nbsp;README.md<br>
	git&nbsp;add&nbsp;README.md<br>
	git&nbsp;commit&nbsp;-m&nbsp;"add&nbsp;README"<br>
	git&nbsp;push&nbsp;-u&nbsp;origin&nbsp;master<br>
>>* 3存在的文件夹
>>>cd&nbsp;existing_folder<br>
	git&nbsp;init<br>
	git&nbsp;remote&nbsp;add&nbsp;origin&nbsp;SSH地址<br>
	git&nbsp;add&nbsp;.<br>
	git&nbsp;commit&nbsp;-m&nbsp;"Initial&nbsp;commit"<br>
	git&nbsp;push&nbsp;-u&nbsp;origin&nbsp;master<br>
>>* 存在的Git库
>>>cd&nbsp;existing_repo<br>
	git&nbsp;remote&nbsp;add&nbsp;origin&nbsp;SSH地址<br>
	git&nbsp;push&nbsp;-u&nbsp;origin&nbsp;--all<br>
	git&nbsp;push&nbsp;-u&nbsp;origin&nbsp;--tags<br>

### 常用的git命令
>>* git&nbsp;add<br>
    跟踪某一个文件夹<br>
    git&nbsp;add&nbsp;文件名&
>>* git&nbsp;commit<br>
    Git&nbsp;仓库中的提交记录保存的是你的目录下所有文件的快照，就像是把整个目录复制，然后再粘贴一样，但比复制粘贴优雅许多！<br>
    Git&nbsp;希望提交记录尽可能地轻量，因此在你每次进行提交时，它并不会盲目地复制整个目录。条件允许的情况下，它会将当前版本与仓库中的上一个版本进行对比，并把所有的差异打包到一起作为一个提交记录。<br>
    Git&nbsp;还保存了提交的历史记录。这也是为什么大多数提交记录的上面都有父节点的原因。对于项目组的成员来说，维护提交历史对大家都有好处。<br>
    现在你可以把提交记录看作是项目的快照。提交记录非常轻量，可以快速地在这些提交记录之间切换！<br>
    git&commit&-m&"修改内容描述"<br>
>>* git&nbsp;branch<br>
    Git&nbsp;的分支也非常轻量。它们只是简单地指向某个提交纪录——仅此而已。所以许多Git爱好者传颂：早建分支！多用分支！<br>
    这是因为即使创建再多分的支也不会造成储存或内存上的开销，并且按逻辑分解工作到不同的分支要比维护那些特别臃肿的分支简单多了。<br>
    在将分支和提交记录结合起来后，我们会看到两者如何协作。现在只要记住使用分支其实就相当于在说：“我想基于这个提交以及它所有的父提交进行新的工作。”<br>
    $git&nbsp;branch&nbsp;//列出本地分支<br>
    $git&nbsp;branch&nbsp;-r&nbsp;//列出远程分支<br>
    $git&nbsp;branch&nbsp;-a&nbsp;//列出所有分支<br>
    $git&nbsp;branch&nbsp;分支名&nbsp;//创建分支<br>
    $git&nbsp;branch&nbsp;-m&nbsp;oldbranchname&nbsp;newbranchname&nbsp;//给分支重新命名<br>
    $git&nbsp;branch&nbsp;-d&nbsp;branchname&nbsp;//删除本地分支<br>
    $git&nbsp;branch&nbsp;-d&nbsp;-r&nbsp;branchname&nbsp;//删除远程分支<br>
>>* git&nbsp;merge<br>
    $git&nbsp;merge&nbsp;fixes&nbsp;enhancements&nbsp;//合并两个分支到当前分支<br>
    $git&nbsp;merge&nbsp;dev&nbsp;//将dev分支和当前分支合并<br>
    $git&nbsp;merge&nbsp;--no-commit&nbsp;maint&nbsp;//不自动更新新的提交<br>   
>>* git&nbsp;rebase<br>
    $git&nbsp;rebase类似$git&nbsp;merge只是合并的时候并不是生成分支的共同字节的，而是在远程分支下添加<br>
>>* git&nbsp;pull(git&nbsp;fetch和git&nbsp;merge的缩写)<br>
    取回远程主机某个分支的更新，再与本地的指定分支合并。一般用于远程分支领先于本地分支<br>
    $git&nbsp;pull&nbsp;origin&nbsp;next:master&nbsp;//远程分支next和master分支合并<br>
    $git&nbsp;pull&nbsp;origin&nbsp;next&nbsp;//远程分支next和当前分支合并<br>
    当使用git&nbsp;branch&nbsp;--set-upstream&nbsp;master&nbsp;origin/next后，追踪远程分支,指定master分支追踪origin/next分支<br>
    $git&nbsp;pull&nbsp;origin&nbsp;//将当前分支和远程next分支合并<br>
>>* git&nbsp;pull&nbsp;发生冲突<br>
    1.$git&nbsp;pull(提示有冲突)<br>
    2.$git&nbsp;stash(暂存自己不一样的东西)<br>
    3.$git&nbsp;pull<br>
    4.$git&nbsp;stash&nbsp;pop&nbsp;stash@{0}(提示有冲突)<br>
    5.修改自己和远程不一样的<br>
      &nbsp;&nbsp;&nbsp;&nbsp;打开有冲突的文件<br>
      &nbsp;&nbsp;&nbsp;&nbsp;<<<<<<<<br>
      &nbsp;&nbsp;&nbsp;&nbsp;...远程的...<br>
      &nbsp;&nbsp;&nbsp;&nbsp;=======<br>
      &nbsp;&nbsp;&nbsp;&nbsp;...本地的...<br>
      &nbsp;&nbsp;&nbsp;&nbsp;>>>>>>><br>
    根据需求进行修改<br>
>>* git&nbsp;fetch<br>
    $git&nbsp;fetch&nbsp;<远程主机名>&nbsp;<分支名><br>
>>* 分离HEAD<br>    
>>>* 相对引用~<br>
    如果你想在提交树中向上移动很多步的话，敲那么多^貌似也挺烦人的，Git当然也考虑到了这一点，于是又引入了操作符~。<br>
    该操作符后面可以跟一个数字（可选，不跟数字时与^相同，向上移动一次），指定向上移动多少次。咱们还是通过实际<br>
    我使用相对引用最多的就是移动分支。可以直接使用 -f 选项让分支指向另一个提交。例如:<br>git&nbsp;branch&nbsp;-f&nbsp;HEAD~n<br>
>>>* 相对引用^<br>
    所以master^相当于“master的父节点”。
>>* 撤销变更<br>
    Git里撤销变更的方法很多。和提交一样，撤销变更由底层部分（暂存区的独立文件或者片段）和上层部分（变更到底是通过哪咱方式被撤销的）组成。我们<br>
    这个应用主要关注的是后者。主要有两种方法用来撤销变更——一是git&;reset，还有就是git&revert。git&reset通过把分支记录回退几个提交记录来实<br>
    现撤销改动。你可以将这想象成“改写历史”。git&;reset向上移动分支，原来指向的提交记录就跟从来没有提交过一样。为了撤销<更改并分享给别人，我们<br>
    需要使用git&nbsp;revert。<br>
>>>* 撤销git&nbsp;commit<br>
        1.$git&nbsp;log&nbsp;//查看提交的SHA,即是commit后面的<br>
        2.$git&nbsp;reset&nbsp;--hard&nbsp;SHA&nbsp;（你想撤销的push前一个）<br>
        3.$git&nbsp;reset&nbsp;SHA<br>
        1,2结合撤销commit并且还撤销代码修改<br>
        1,3只是撤销commit<br>
>>>* 撤销git&push<br>
        1.$git&nbsp;log&nbsp;//查看提交的SHA,即是commit后面的<br>
        2.$git&nbsp;reset&nbsp;--hard&nbsp;SHA&nbsp;（你想撤销的push前一个）<br>
        3.$git&nbsp;push&nbsp;--force&nbsp;branch<br>
        是否加-hard和上面一样<br>
#### 一般的工作流程
>>* 分支介绍：<br>
    master:主分支<br>
    develop:开发分支<br>
    feature:功能分支<br>
    release:发行分支<br>
    hotfix:补丁分支<br>
>>* 分阶段功能<br>
    开发新功能：<br>
    $git&nbsp;branch&nbsp;feature&nbsp;develop创建feature分支,在开发分支处<br>
    $git&nbsp;checkout&nbsp;feature切换到功能分支<br>
    功能完成后<br>
    $git&nbsp;checkout&nbsp;develop切换到开发分支<br>
    $git&nbsp;merge&nbsp;--no-ff&nbsp;feature将功能分支合并到开发分支中<br>
    $git&nbsp;branch&nbsp;-d&nbsp;feature删除功能分支<br>
    $git&nbsp;push&nbsp;origin&nbsp;develop放入开发库中<br>
>>* 新版本集成、准备发行<br>
    $git&nbsp;branch&nbsp;release1.2&nbsp;develop创建发行分支,在开发分支处<br>
    $git&nbsp;checkout&nbsp;release切换到发行分支<br>
    $./bump-version.sh&nbsp;1.2(修改元数据文件中的版本，可手动操作)<br>
    $git&nbsp;commit&nbsp;-a-m&nbsp;"Bumped&nbsp;version&nbsp;number&nbsp;to&nbsp;1.2"提交到暂存态<br>
    $git&nbsp;checkout&nbsp;master切换到主分支<br>
    $git&nbsp;merge&nbsp;--no-ff&nbsp;release-1.2将发行分支合并到主分支<br>
    $git&nbsp;tag&nbsp;-a&nbsp;1.2在该主分支上打上标记<br>
    $git&nbsp;checkout&nbsp;develop切换到开发分支<br>
    $git&nbsp;merge&nbsp;--no-ff&nbsp;release-1.2将发行分支合并到开发分支<br>
    $git&nbsp;branch&nbsp;-d&nbsp;release&nbsp;-1.2删除开发分支<br>
>>* 开发版本补丁
    $git&nbsp;branch&nbsp;hotfix-1.2.1&nbsp;master在master处创建补丁分支<br>
    $./bump-version.sh&nbsp;1.2.1(修改元数据文件中的版本，可手动操作)<br>
    $git&nbsp;commit&nbsp;-a-m&nbsp;"Bumped&nbsp;version&nbsp;number&nbsp;to&nbsp;1.2.1"提交到暂存态<br>
    $git&nbsp;commit&nbsp;-m&nbsp;"Fixed&nbsp;severe&nbsp;production&nbsp;problem"提交补丁 修改
    $git&nbsp;checkout&nbsp;master切换主分主<br>
    $git&nbsp;merge&nbsp;--no-ff&nbsp;hotfix-1.2.1合并到主分主<br>
    $git&nbsp;tag&nbsp;-a&nbsp;1.2.1在该分支处打上标记1.2.1<br>
    $git&nbsp;checkout&nbsp;develop切换到开发分支<br>
    $git&nbsp;merge&nbsp;--no-ff&nbsp;hotfix-1.2.1将补丁分支合并到开发分支中<br>
    $git&nbsp;branch&nbsp;-d&nbsp;hotfix-1.2.1删除补丁分支<br>