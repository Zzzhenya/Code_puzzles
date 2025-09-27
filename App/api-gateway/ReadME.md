API gateway
* entry point to all external requests
* handles : 
    routing : Forward requests to correct microservice
    authentication: Validate JWT tokens or session
    rate limiting: Prevent abuse
    logging: Log incoming requests and responses
    request transformation: Modify headers, paths, or body
    response handling: Format or sanitize responses
* Proxies or forwards requests to your internal microservices (users, orders, products, etc.)



// installing "fastify-http-proxy": "^6.2.2",
undici  <=5.28.5
Severity: high
undici before v5.8.0 vulnerable to CRLF injection in request headers - https://github.com/advisories/GHSA-3cvr-822r-rqcc
ProxyAgent vulnerable to MITM - https://github.com/advisories/GHSA-pgw7-wx7w-2w33
undici before v5.8.0 vulnerable to uncleared cookies on cross-host / cross-origin redirect - https://github.com/advisories/GHSA-q768-x9m6-m9qp
Nodejs ‘undici’ vulnerable to CRLF Injection via Content-Type - https://github.com/advisories/GHSA-f772-66g8-q5h3
`undici.request` vulnerable to SSRF using absolute URL on `pathname` - https://github.com/advisories/GHSA-8qr4-xgw6-wmr3
Regular Expression Denial of Service in Headers - https://github.com/advisories/GHSA-r6ch-mqf9-qc9w
CRLF Injection in Nodejs ‘undici’ via host - https://github.com/advisories/GHSA-5r9g-qh6m-jxff
Undici's cookie header not cleared on cross-origin redirect in fetch - https://github.com/advisories/GHSA-wqq4-5wpv-mx2g
Undici's fetch with integrity option is too lax when algorithm is specified but hash value is in incorrect - https://github.com/advisories/GHSA-9qxr-qj54-h672
Undici proxy-authorization header not cleared on cross-origin redirect in fetch - https://github.com/advisories/GHSA-3787-6prv-h9w3
Use of Insufficiently Random Values in undici - https://github.com/advisories/GHSA-c76h-2ccp-4975
Undici's Proxy-Authorization header not cleared on cross-origin redirect for dispatch, request, stream, pipeline - https://github.com/advisories/GHSA-m4v8-wqvr-p9f7
undici Denial of Service attack via bad certificate data - https://github.com/advisories/GHSA-cxrh-j4jr-qwg3
fix available via `npm audit fix`
node_modules/undici
  fastify-reply-from  0.5.0 - 6.6.0
  Depends on vulnerable versions of undici
  node_modules/fastify-reply-from

// after audit fix

# npm audit report

fast-jwt  <=5.0.5
Severity: moderate
JWT Algorithm Confusion - https://github.com/advisories/GHSA-c2ff-88x2-x9pg
Fast-JWT Improperly Validates iss Claims - https://github.com/advisories/GHSA-gm45-q3v2-6cf8
No fix available
node_modules/fast-jwt
  fastify-jwt  *
  Depends on vulnerable versions of fast-jwt
  node_modules/fastify-jwt
  node_modules/fastify-jwt-deprecated

fastify-http-proxy  *
Depends on vulnerable versions of fastify-reply-from
Depends on vulnerable versions of fastify-reply-from - null
No fix available
node_modules/fastify-http-proxy
node_modules/fastify-http-proxy-deprecated


fastify-reply-from  *
Depends on vulnerable versions of undici - null
Depends on vulnerable versions of undici
No fix available
node_modules/fastify-reply-from
node_modules/fastify-reply-from-deprecated

undici  <=5.28.5
Severity: high
undici before v5.8.0 vulnerable to CRLF injection in request headers - https://github.com/advisories/GHSA-3cvr-822r-rqcc
ProxyAgent vulnerable to MITM - https://github.com/advisories/GHSA-pgw7-wx7w-2w33
undici before v5.8.0 vulnerable to uncleared cookies on cross-host / cross-origin redirect - https://github.com/advisories/GHSA-q768-x9m6-m9qp
Nodejs ‘undici’ vulnerable to CRLF Injection via Content-Type - https://github.com/advisories/GHSA-f772-66g8-q5h3
`undici.request` vulnerable to SSRF using absolute URL on `pathname` - https://github.com/advisories/GHSA-8qr4-xgw6-wmr3
Regular Expression Denial of Service in Headers - https://github.com/advisories/GHSA-r6ch-mqf9-qc9w
CRLF Injection in Nodejs ‘undici’ via host - https://github.com/advisories/GHSA-5r9g-qh6m-jxff
Undici's cookie header not cleared on cross-origin redirect in fetch - https://github.com/advisories/GHSA-wqq4-5wpv-mx2g
Undici's fetch with integrity option is too lax when algorithm is specified but hash value is in incorrect - https://github.com/advisories/GHSA-9qxr-qj54-h672
Undici proxy-authorization header not cleared on cross-origin redirect in fetch - https://github.com/advisories/GHSA-3787-6prv-h9w3
Use of Insufficiently Random Values in undici - https://github.com/advisories/GHSA-c76h-2ccp-4975
Undici's Proxy-Authorization header not cleared on cross-origin redirect for dispatch, request, stream, pipeline - https://github.com/advisories/GHSA-m4v8-wqvr-p9f7
undici Denial of Service attack via bad certificate data - https://github.com/advisories/GHSA-cxrh-j4jr-qwg3
No fix available
node_modules/undici

5 vulnerabilities (2 low, 2 moderate, 1 high)

Some issues need review, and may require choosing
a different dependency.
