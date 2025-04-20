# Fork of the Source SDK 2013
## With faster Shader Compile Times!

You will find modified versions of the Pixels Shaders in this Repo for LightmappedGeneric and VertexLitGeneric.
I optimised and tested these on my AMD R9 5950x.
Functionally they should work identically to Stock Shaders, except some features that were previously broken will work now
( Detailblendmode 5 & 6 on Bumped VLG, for example )

Heres some charts to visualise the changes.
I haven't compiled stock LMG ( because it takes ludicriously long ), so to stay fair I set its time in the diagram to 0
When I get the time I will update this description..

NOTE:
The only real things that changed on these Shaders is the Static and Dynamic Combos.
I compressed them to avoid SKIP statements, and decompress them afterwards.
The Compiler didn't like the bools it made from statics now that they are defines instead, so I removed them :)
I slightly organised things, added some minor comments and also copied some missing code ( Blendmode 5&6 on Bumped VLG )
![firefox_UN7mWUgnHn](https://github.com/user-attachments/assets/826a2719-42c6-4257-85a9-a71d48d87317)
![firefox_sy1EaXvJxU](https://github.com/user-attachments/assets/754cf3fb-3deb-4e73-8d80-d4d0f7cdd940)


## License

The SDK is licensed to users on a non-commercial basis under the [SOURCE 1 SDK LICENSE](LICENSE), which is contained in the [LICENSE](LICENSE) file in the root of the repository.

For more information, see [Distributing your Mod](#markdown-header-distributing-your-mod).
