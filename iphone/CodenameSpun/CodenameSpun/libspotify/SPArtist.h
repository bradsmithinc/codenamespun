//
//  SPArtist.h
//  CocoaLibSpotify
//
//  Created by Daniel Kennett on 2/20/11.
/*
Copyright (c) 2011, Spotify AB
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Spotify AB nor the names of its contributors may 
      be used to endorse or promote products derived from this software 
      without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL SPOTIFY AB BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/** Represents an artist on Spotify.
 
 SPArtist  is roughly analogous to the sp_artist struct in the C LibSpotify API.
 */

#import <Foundation/Foundation.h>
#import "CocoaLibSpotifyPlatformImports.h"

@interface SPArtist : NSObject {
    @private
    sp_artist *artist;
}

///----------------------------
/// @name Creating and Initializing Artists
///----------------------------

/** Creates an SPArtist from the given opaque sp_artist struct. 
 
 This convenience method creates an SPArtist object if one doesn't exist, or 
 returns a cached SPArtist if one already exists for the given struct.
 
 @param anArtist The sp_artist struct to create an SPArtist for.
 @return Returns the created SPArtist object. 
 */
+(SPArtist *)artistWithArtistStruct:(sp_artist *)anArtist;

/** Creates an SPArtist from the given Spotify artist URL. 
 
 This convenience method creates an SPArtist object if one doesn't exist, or 
 returns a cached SPArtist if one already exists for the given URL.
 
 @warning *Important:* If you pass in an invalid artist URL (i.e., any URL not
 starting `spotify:artist:`, this method will return `nil`.
 
 @param aURL The artist URL to create an SPArtist for.
 @return Returns the created SPArtist object, or `nil` if given an invalid artist URL. 
 */
+(SPArtist *)artistWithArtistURL:(NSURL *)aURL;

/** Initializes a new SPArtist from the given opaque sp_artist struct. 
 
 @warning *Important:* For better performance and built-in caching, it is recommended
 you create SPArtist objects using +[SPArtist artistWithArtistStruct:], 
 +[SPArtist artistWithArtistURL:] or the instance methods on SPSession.
 
 @param anArtist The sp_artist struct to create an SPArtist for.
 @return Returns the created SPArtist object. 
 */
-(id)initWithArtistStruct:(sp_artist *)anArtist;

///----------------------------
/// @name Properties
///----------------------------

/** Returns the opaque structure used by the C LibSpotify API. 
 
 @warning *Important:* This should only be used if you plan to directly use the 
 C LibSpotify API. The behaviour of CocoaLibSpotify is undefined if you use the C
 API directly on items that have CocoaLibSpotify objects associated with them. 
 */
@property (readonly) sp_artist *artist;

///----------------------------
/// @name Metadata
///----------------------------

/** Returns the artist's name. */
@property (readonly) NSString *name;

@end
