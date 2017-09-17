/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef JAVA_NET_URL_CONNECTION_HPP_
#define JAVA_NET_URL_CONNECTION_HPP_

#include "../../Lang.hpp"
#include "../URL/URL.hpp"
#include "../../util/HashMap/HashMap.hpp"

namespace Java {
    namespace Net {
        class URLConnection : public Object{
        private:
            int connectTimeout;
            int readTimeout;
        protected:
            URL url;
            boolean doInput = true;
            boolean doOutput = false;
            boolean connected = false;
            long ifModifiedSince;
            boolean allowUserInteraction;
            boolean useCaches;
        public:
            URLConnection();
            URLConnection(URL url);
            ~URLConnection();

        public:

            /**
             * Returns the value of this URLConnection's URL field.
             *
             * @return the value of this URLConnection's URL field.
             */
            URL getURL();

            /**
             * Sets the value of the doInput field for
             * this URLConnection to the specified value.
             * A URL connection can be used for input and/or output.
             * Set the DoInput flag to true if you intend to use
             * the URL connection for input, false if not.
             * The default is true
             *
             * @param doInput
             */
            void setDoInput(boolean doInput);

            /**
             * Returns the value of this URLConnection's doInput flag.
             *
             * @return the value of this URLConnection's doInput flag.
             */
            boolean getDoInput();

            /**
             * Sets the value of the doOutput field for
             * this URLConnection to the specified value.
             * A URL connection can be used for input and/or output.
             * Set the DoOutput flag to true if you intend to use
             * the URL connection for output, false if not.
             * The default is false
             *
             * @param doOutput
             */
            void setDoOutput(boolean doOutput);

            /**
            * Returns the value of this URLConnection's doOutput flag.
            *
            * @return the value of this URLConnection's doOutput flag.
            */
            boolean getDoOutput();

            /**
             * Sets the value of the useCaches field of this URLConnection
             * to the specified value.
             * Some protocols do caching of documents.
             * Occasionally, it is important to be able to "tunnel through"
             * and ignore the caches (e.g., the "reload" button in a browser).
             * If the UseCaches flag on a connection is true,
             * the connection is allowed to use whatever caches it can.
             * If false, caches are to be ignored.
             * The default value comes from DefaultUseCaches,
             * which defaults to true.
             *
             * @param useCaches
             * @throw java.lang.IllegalStateException if already connected
             */
            void setUseCaches(boolean useCaches);

            /**
             * Returns the value of this URLConnection's useCaches field.
             *
             * @return the value of this URLConnection's useCaches field.
             */
            boolean getUseCaches();

            /**
             * Sets the value of the ifModifiedSince field
             * of this URLConnection to the specified value.
             *
             * @param ifModifiedSince
             * @throw java.lang.IllegalStateException if already connected
             */
            void setIfModifiedSince(long ifModifiedSince);

            /**
             * Returns the value of this object's ifModifiedSince field.
             *
             * @return the value of this object's ifModifiedSince field.
             */
            long getIfModifiedSince();

            /**
             * Sets the read timeout to a specified timeout, in milliseconds.
             * A non-zero value specifies the timeout when reading
             * from Input stream when a connection is established to a resource.
             * If the timeout expires before there is data available for read,
             * a java.net.SocketTimeoutException is raised.
             * A timeout of zero is interpreted as an infinite timeout.
             * Some non-standard implementation of this method
             * ignores the specified timeout.
             * To see the read timeout set, please call getReadTimeout().
             *
             * @param timeout
             * @throw java.lang.IllegalArgumentException
             * if the timeout parameter is negative
             */
            void setReadTimeout(int timeout);

            /**
             * Returns setting for read timeout.
             * 0 return implies that the option is disabled
             *
             * @return an int that indicates the read timeout value in milliseconds
             */
            int getReadTimeout();

            /**
             * Set the value of the allowUserInteraction field of this URLConnection.
             *
             * @param allowUserInteraction
             * @throw java.lang.IllegalStateException if already connected
             */
            void setAllowUserInteraction(boolean allowUserInteraction);

            /**
             * Returns the value of the allowUserInteraction field for this object.
             *
             * @return the value of the allowUserInteraction field for this object.
             */
            boolean getAllowUserInteraction();

            /**
             * Sets a specified timeout value, in milliseconds,
             * to be used when opening a communications link to the resource
             * referenced by this URLConnection.
             * If the timeout expires before the connection can be established,
             * a java.net.SocketTimeoutException is raised.
             * A timeout of zero is interpreted as an infinite timeout.
             * Some non-standard implementation of this method may
             * ignore the specified timeout.
             * To see the connect timeout set, please call getConnectTimeout().
             *
             * @param timeout
             */
            void setConnectTimeout(int timeout);

            /**
             * Returns setting for connect timeout.
             * 0 return implies that the option is disabled.
             *
             * @return an int that indicates the connect timeout value in milliseconds
             */
            int getConnectTimeout();

            /**
             * Opens a communications link to the resource referenced by this URL,
             * if such a connection has not already been established.
             * If the connect method is called when the connection
             * has already been opened
             * (indicated by the connected field having the value true),
             * the call is ignored.
             * URLConnection objects go through two phases:
             * first they are created, then they are connected.
             * After being created, and before being connected,
             * various options can be specified (e.g., doInput and UseCaches).
             * After connecting, it is an error to try to set them.
             * Operations that depend on being connected, like getContentLength,
             * will implicitly perform the connection, if necessary.
             *
             * @throw SocketTimeoutException if the timeout expires
             * before the connection can be established
             * @throw java.io.IOException if an I/O error occurs while opening the connection.
             */
            virtual void connect() = 0;

            /**
             * Returns the value of the content-encoding header field.
             *
             * @return the content encoding of the resource
             * that the URL references, or null if not known.
             */
            String getContentEncoding();

            /**
             * Returns the value of the content-length header field.
             * Note: getContentLengthLong() should be preferred over this method,
             * since it returns a long instead and is therefore more portable.
             *
             * @return the content length of the resource that
             * this connection's URL references,
             * -1 if the content length is not known,
             * or if the content length is greater than Integer.MAX_VALUE.
             */
            int getContentLength();

            /**
             * Returns the value of the content-type header field.
             *
             * @return the content type of the resource that the URL references,
             * or null if not known.
             */
            String getContentType();

            /**
             * Returns an unmodifiable Map of general request properties
             * for this connection. The Map keys are Strings that represent
             * the request-header field names. Each Map value is
             * a unmodifiable List of Strings that represents the corresponding field values.
             *
             * @throw java.lang.IllegalStateException if already connected
             * @return a Map of the general request properties for this connection.
             */
            HashMap< String, Array<String> > getRequestProperties();

            /**
             * Returns the value of the named general request property for this connection.
             *
             * @param key
             * @throw java.lang.IllegalStateException if already connected
             * @return the value of the named general request property for this connection.
             * If key is null, then null is returned.
             */
            // TODO (anhnt) need MessageHeader
            //String getRequestProperty(String key);

            /**
             * Sets the general request property.
             * If a property with the key already exists,
             * overwrite its value with the new value.
             * NOTE: HTTP requires all request properties which can legally
             * have multiple instances with the same key to use
             * a comma-separated list syntax which enables multiple properties
             * to be appended into a single property.
             *
             * @param key
             * @param value
             * @throw java.lang.IllegalStateException if already connected
             */
            // TODO (anhnt) need MessageHeader
           // void setRequestProperty(String key, String value);

            /**
             * Returns a String representation of this URL connection.
             *
             * @return a string representation of this URLConnection.
             */
            string toString() const override;
        };
    }
}
#endif  // JAVA_NET_URL_CONNECTION_HPP_